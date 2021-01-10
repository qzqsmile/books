package main

import "fmt"

//Fan-Out, Fan-In 的 concurrency pattern。
//其本质是流水线工作的抽象。将每个工人抽象为一个goroutine
// 同时可以抽象出多个流水线，以加快运行速度。即Fan-Out, Fan-In的根本思想

func main() {
	generator := func(done <-chan interface{}, integers ...int) <-chan int {
		intStream := make(chan int)
		go func() {
			defer close(intStream)
			for _, i := range integers {
				select { case <-done:
					return
				case intStream <- i: }
			}
		}()
		return intStream
	}

	multiply := func(
		done <-chan interface{}, intStream <-chan int, multiplier int,
	) <-chan int {
		multipliedStream := make(chan int)
		go func() {
			defer close(multipliedStream)
			for i := range intStream {
				select { case <-done:
					return
				case multipliedStream <- i * multiplier: }
			}
		}()
		return multipliedStream
	}
	add := func(
		done <-chan interface{}, intStream <-chan int, additive int,
	) <-chan int {
		addedStream := make(chan int)
		go func() {
			defer close(addedStream)
			for i := range intStream {
				select { case <-done:
					return
				case addedStream <- i + additive: }
			}
		}()
		return addedStream
	}

	done := make(chan interface{})
	defer close(done)
	intStream := generator(done, 1, 2, 3, 4)
	pipeline := multiply(done, add(done, multiply(done, intStream, 2), 1), 2)
	for v := range pipeline {
		fmt.Println(v)
	}
}
