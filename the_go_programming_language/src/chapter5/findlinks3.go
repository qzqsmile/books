package main

import (
	"fmt"
	"time"
)

func main(){
	ch := make(chan struct{})
	go func() {
		time.Sleep(2*time.Second)
		close(ch)
		//ch<- struct{}{}
	}()

	select {
		case <-ch:
			fmt.Println("1")
		case <-ch:
			fmt.Println("2")
	}
}

