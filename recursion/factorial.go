package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"runtime/pprof"
)

func RecursiveFactorial(pn uint) uint {
	if pn == 0 {
		return 1
	}
	return pn * RecursiveFactorial(pn-1)
}

var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to a file")
var num = flag.Uint("number", 10, "number to determine it's factorial")

func main() {
	// goTesting -cpuprofile and -memprofile is
	// a better way to achieve this.
	flag.Parse()
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile)
		if err != nil {
			log.Fatal(err)
		}
		pprof.StartCPUProfile(f)

		var n uint = *num
		x := RecursiveFactorial(n)
		fmt.Println(*num, x)

		defer pprof.StopCPUProfile()
	}
	var n uint = *num
	x := RecursiveFactorial(n)
	fmt.Printf("Factorial of %d is: %d\n", n, uint(x))
}
