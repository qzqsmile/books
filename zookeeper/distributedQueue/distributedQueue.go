package main

import (
	"fmt"
	"github.com/samuel/go-zookeeper/zk"
	"log"
	"sort"
	"time"
)



func main() {
	c, _, err := zk.Connect([]string{"127.0.0.1:2181"}, 60*time.Second) //*10)
	defer c.Close()
	if err != nil {
		panic(err)
	}
	//fmt.Printf("res is %v", res)
	ch := make(chan struct{})
	d := distributedQueue{conn: c}
	d.path= "/"
	//delete existed nodes
	d.clear()
	go func() {
		count := 0
		for {
			time.Sleep(3*time.Second)
			d.offer([]byte(string(count)))
			count += 1
		}
	}()

	go func() {
		for true {
			time.Sleep(3 * time.Second)
			b, err := d.poll()
			fmt.Printf("poll out is %v, %v\n", b, err)
		}
	}()

	go func() {
		time.Sleep(10*time.Second)
		ch<- struct{}{}
	}()
	<-ch
}


type distributedQueue struct{
	root string
	conn *zk.Conn
	path string
}


func (d *distributedQueue) offer(bytes []byte) error{
	var flags int32 = zk.FlagSequence
	var acls = zk.WorldACL(zk.PermAll)
	s, err := d.conn.Create(d.path, bytes, flags, acls)
	if err != nil{
		return err
	}
	fmt.Printf("insert node %v ", s)
	return nil
}


func (d *distributedQueue) poll() ([]byte, error){
	children, _, _ := d.conn.Children(d.path)
	sort.Strings(children)
	for _, v := range children{
		b, s, err := d.conn.Get(d.path+v)
		//delete by another process
		if err != nil{
			continue
		}
		//delete by another process
		if err := d.conn.Delete(d.path+v, s.Version); err != nil{
			continue
		}
		//delete by this
		fmt.Printf("delete path is %v ", d.path+v)
		return b, nil
	}
	return []byte{}, nil
}

func (d *distributedQueue) clear() error{
	children, s, err := d.conn.Children(d.path)
	if err != nil{
		log.Fatal(err)
		//fmt.Printf("error occurs in clear %v", err)
		return err
	}
	for _, v := range children{
		if err := d.conn.Delete(d.path+v, s.Version);  err == zk.ErrConnectionClosed{
			c, _, err := zk.Connect([]string{"127.0.0.1:2181"}, time.Second)
			if err != nil{
				log.Fatal(err)
			}
			d.conn = c
		}
	}
	return nil
}