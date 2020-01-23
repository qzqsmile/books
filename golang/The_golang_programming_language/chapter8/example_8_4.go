package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"os"
)

func demo84() {
	conn, err := net.Dial("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	done := make(chan struct{})
	go func() {
		io.Copy(os.Stdout, conn) // NOTE: ignoring errors log.Println("done")
		done <- struct{}{}       // signal the main goroutine
	}()
	mustCopy(conn, os.Stdin)
	conn.Close()
	<-done // wait for background goroutine to finish
}


func demo842(){
	naturals := make(chan int)
	squares := make(chan int)
	// Counter
	go func() {
		for x := 0; x < 100 ; x++ {
			naturals <- x
		}
		close(naturals)
		}()
	// Squarer
	go func() {
		for x := range naturals {
			squares <- x * x
		}
		close(squares)
	}()
	// Printer (in main goroutine)
	for x := range squares {
		fmt.Println(x)
	}
}

func counter(out chan<- int) {
	for x := 0; x < 100; x++ {
		out <- x
	}
	close(out)
}
func squarer(out chan<- int, in <-chan int) {
	for v := range in {
		out <- v * v
	}
	close(out)
}
func printer(in <-chan int) {
	for v := range in {
		fmt.Println(v)
	}
}

func demo843(){
	naturals := make(chan int)
	squares := make(chan int)
	go counter(naturals)
	go squarer(squares, naturals)
	printer(squares)

}

func mydemo(){
	s := make(chan int)
	go func(){
		close(s)
	}()

	fmt.Println(<-s)
}