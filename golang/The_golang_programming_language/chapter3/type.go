package main

import "fmt"

func main() {
	//var s uint16、
	//s := []int{0, 1, 2, 3, 4, 5, 6}
	//s1 := s[1:3]
	//s1[0] = 121
	//fmt.Println(s)
	data := []string{"one", "", "three"}
	data1 := nonempty2(data)
	fmt.Println(data,data1)
	//s2 := string(b)
}

func nonempty2(strings []string) []string {
	out := strings[:0] // zero-length slice of original for _, s := range strings {
	for _, s := range strings {
		if s != "" {
			out = append(out, s)
		}
	}
	return out
}
