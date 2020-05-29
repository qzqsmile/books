package main

import "fmt"

func main()  {
	fmt.Printf("%v", c())
}

func c() (i int) {
	defer func() { i++ }()
	return 1
}