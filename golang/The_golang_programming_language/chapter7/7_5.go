package main

import (
	"io"
	"sort"
)

const debug = true

type StringSlice []string


func (p StringSlice) Len() int           { return len(p) }
func (p StringSlice) Less(i, j int) bool { return p[i] < p[j] }
func (p StringSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }


func man() {
	var names StringSlice
	sort.Sort(StringSlice(names))
}

// If out is non-nil, output will be written to it. func f(out io.Writer) {
// ...do something...
func f(out io.Writer) {
	rune()
	// ...do something...
	if out != nil {
		out.Write([]byte("done!\n"))
	}
}
