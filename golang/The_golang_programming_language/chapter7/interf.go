package main

import (
	"bytes"
	"io"
	"os"
)

func main(){
	var w io.Writer
	var rwc io.ReadWriteCloser
	rwc = os.Stdout
	rwc = new(bytes.Buffer)

	w = rwc
}
