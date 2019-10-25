package main

import "fmt"

type ByteCounter int

type Reader interface {
	Read(p []byte) (n int, err error)
}
type Closer interface {
	Close() error
}


func main()  {
	var c ByteCounter
	c.Write([]byte("hello"))
	fmt.Println(c)

	c = 0 // reset the counter
    var name = "Dolly"
    fmt.Fprintf(&c, "hello, %s", name)
    fmt.Println(c) // "12", = len("hello, Dolly")
}