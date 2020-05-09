package main

import (
	"fmt"
	"os"
	"sync"
	"time"
)

var wg sync.WaitGroup
var done = make(chan struct{})

// help method not used here

func worker1() {
	defer wg.Done()
	for {
		select {
		case <-done:
			return
		default:
			// do real things
			time.Sleep(1 * time.Second)
			fmt.Println("worker1 running...")
		}
	}
}

func worker2() {
	defer wg.Done()
	for {
		select {
		case <-done:
			return
		default:
			// do real things
			time.Sleep(1 * time.Second)
			fmt.Println("worker2 running...")
		}
	}
}

func main() {
	go func() {
		os.Stdin.Read(make([]byte, 1)) // 按 enter 建结束
		close(done)
	}()

	wg.Add(2)
	go worker1()
	go worker2()

	wg.Wait()
	fmt.Println("main exists")
}