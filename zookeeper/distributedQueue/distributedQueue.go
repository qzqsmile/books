package main

import (
	"fmt"
	"github.com/samuel/go-zookeeper/zk"
	"sort"
	"time"
)

func main() {
	c, _, err := zk.Connect([]string{"127.0.0.1:2181"}, time.Second) //*10)
	defer c.Close()
	if err != nil {
		panic(err)
	}
	//fmt.Printf("res is %v", res)
	var ch chan struct{}
	d := distributedQueue{conn: c}
	d.path = "/zk_queue_"
	d.clear()
	go func() {
		for i := 0; i < 10; i++ {
			d.offer([]byte(string(i)))
		}
	}()
	go func() {
		time.Sleep(3 * time.Second)
		b, err := d.poll()
		fmt.Printf("%v, %v", b, err)
	}()

	<-ch
}

type distributedQueue struct {
	root string
	conn *zk.Conn
	path string
}


func (d distributedQueue) offer(bytes []byte) error {
	var flags int32 = zk.FlagSequence
	var acls = zk.WorldACL(zk.PermAll)
	s, err := d.conn.Create(d.path, bytes, flags, acls)
	if err != nil {
		return err
	}
	fmt.Printf("insert ndoe %v", s)
	return nil
}

func (d distributedQueue) poll() ([]byte, error) {
	children, s, _ := d.conn.Children(d.path)
	sort.Strings(children)
	for _, v := range children {
		if err := d.conn.Delete(d.path+v,s.Version); err != nil{
			continue
		}else{

		}
	}
	return []byte{}, nil
}

func (d distributedQueue) clear() error {
	children, s, err := d.conn.Children(d.path)
	if err != nil {
		fmt.Printf("error occurs in clear %v", err)
		return err
	}
	for _, v := range children {
		d.conn.Delete(v, s.Version)
	}
	return nil
}
