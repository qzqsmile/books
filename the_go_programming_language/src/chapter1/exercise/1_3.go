package main

import (
	"fmt"
	"strings"
	"time"
)

func main() {
	s := []string{}
	for i := 0; i < 100000; i++{
		s = append(s, "a")
	}


	t := time.Now()
	strings.Join(s, "")
	fmt.Println("Join use %v time", time.Now().Sub(t))
	t = time.Now()
	s1 := ""
	for i := 0; i < 100000; i++{
		s1 += "a"
	}
	fmt.Println("plus use %v time", time.Now().Sub(t))
}
