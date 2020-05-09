package main

import (
	"fmt"
)

// 1
// func main(){
// 	fmt.Println("hello world!");
	
// }

// 2
// func main(){
// 	x := 100
// 	switch  {
// 		case x > 0:
// 			fmt.Println("x");
// 		case x < 0:
// 			fmt.Println("-x");
// 		default:
// 			fmt.Println("0");
// 	}
// }

type X int 

func (x *X) inc() {
	*x++
}

func main(){
	var x X
	x.inc()
	fmt.Println(x)
}
