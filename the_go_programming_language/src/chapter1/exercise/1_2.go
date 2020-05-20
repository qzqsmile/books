package main

import (
	"fmt"
	"os"
)


func main() {
	for k, c := range os.Args {
		if k > 0 {
			fmt.Printf("%v\t%v\n", k, c)
		}
	}
}
