package main

import (
	"fmt"
	"reflect"
)

func main () {
	t := reflect.TypeOf(3)  // a reflect.Type
	fmt.Println(t.String()) // "int"
	fmt.Println(t.Kind())          // "int"
}

