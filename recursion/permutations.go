package main

import "fmt"

// aliases
// Byte = Uint8
// Rune = Int32

func main() {
	list := []byte{'b', 'a', 'd', 'r'}
	list = append(list, 'c')
	var n int = len(list)

	permutations(list, 0, n-1)
}

func permutations(plist []byte, pi int, pn int) {
	var j int
	if pi == pn {
		fmt.Println(plist)
	}

	for j = pi; j < pn ; j++ {
		swap(&plist[pi], &plist[j])
		permutations(plist, pi+1, pn)
		swap(&plist[j], &plist[pi])
	}
}

func swap (ci *byte, cj *byte) {
	*ci, *cj = *cj, *ci
}
