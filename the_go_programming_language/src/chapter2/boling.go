package main

const boilingF = 212.0

var a = b + c
var b = f()
var c = 1
// a initialized third, to 3
// b initialized second, to 2, by calling f
// c initialized first, to 1
func f() int { return c + 1 }