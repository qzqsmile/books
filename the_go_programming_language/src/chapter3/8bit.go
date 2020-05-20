package main

import "fmt"

func main() {
	var x uint8 = 1 << 1 | 1 << 5
	for i := uint(1); i < 8; i++ {
		if x&(1<<i) != 0 { // membership test
			fmt.Println(i) // "1", "5"
		}
	}
}
