package popcount

// pc[i] is the population count of i.

var pc [256]byte
func init() {
	for i := range pc {
		pc[i] = pc[i/2] + byte(i&1)
	}
}
// PopCount returns the population count (number of set bits) of x.
func PopCount(x uint64) int {
	return int(pc[byte(x>>(0*8))] +
		pc[byte(x>>(1*8))] +
		pc[byte(x>>(2*8))] +
		pc[byte(x>>(3*8))] +
		pc[byte(x>>(4*8))] +
		pc[byte(x>>(5*8))] +
		pc[byte(x>>(6*8))] +
		pc[byte(x>>(7*8))])
}

func PopCountIter(x uint64) int{
	var s byte
	for i := 0; i < 8; i++{
		s += pc[byte(x>>(uint(i*8)))]
	}
	return int(s)
}

func PopCountRight(x uint64)int{
	c := 0
	for i := 0; i < 64; i++{
		r := x % 2
		x >>= 1
		if r == 1{
			c++
		}
	}
	return c
}