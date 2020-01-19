package main

import (
	"fmt"
)

// func const_test(){
// 	const (
// 		x, y int  = 99, -999
// 		b byte = byte(x)
// 		n = uint8(y)
// 	)
// }

func enum_const(){
	const (
		x = iota
		y 
		z
	)
	fmt.Printf("%T %v",x, x)
}