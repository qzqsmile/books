package main

import "fmt"

func main() {
	m := make(map[string] int)
	m["1"] = 1
	m["2"] = 2
	for str, i := range m{
		fmt.Println(str, i)
	}
}