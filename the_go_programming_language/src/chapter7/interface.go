package main

import (
	"bytes"
	"io"
	"os"
)

type ByteCounter int

type Reader interface {
	Read(p []byte) (n int, err error)
}
type Closer interface {
	Close() error
}


func main()  {
	//var c ByteCounter
	//c.Write([]byte("hello"))
	//fmt.Println(c)
	var w io.Writer
	w = os.Stdout
	w = new(bytes.Buffer)
	w = nil
	w.Write([]byte("hello"))

	//c = 0 // reset the counter
    //var name = "Dolly"
    //fmt.Fprintf(&c, "hello, %s", name)
    //fmt.Println(c) // "12", = len("hello, Dolly")
}