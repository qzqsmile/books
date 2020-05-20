package main

import (
	"bytes"
	"fmt"
)

func comma(s string) string {
	var buf bytes.Buffer
	for i := 0; i < len(s); i++{
		buf.WriteByte(s[i])
		if (i+1)%3 == 0 && (i != len(s)-1){
			buf.WriteByte(',')
		}
	}
	return buf.String()
}

func main(){
	fmt.Printf(comma("123456"))
}
