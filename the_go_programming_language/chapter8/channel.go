package main

import (
	"fmt"
	"time"
)

func main() {
	naturals := make(chan int)
	squares := make(chan int)
	// Counter
	go func() {
		for x := 0; ; x++ {
			time.Sleep(100 * 1000 * 1000 * 1)
			naturals <- x
			close(naturals)
		}
	}()
	// Squarer
	go func() {
		for {
			x, ok := <-naturals
			if !ok {
				fmt.Println("Error")
				break
			}
			squares <- x * x
		}
	}()
	// Printer (in main goroutine)
	for {
		fmt.Println(<-squares)
	}
}
