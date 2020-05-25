package main

import "fmt"

func main() {
	var a [3]int
	// a = append(a, 1)
	a = [3]int{1,2,3}
	a = append(a, 4)
	fmt.Println(a[0])
}
