
package main

import "fmt"

func main() {
	var number []int
	
	numbers = append(numbers, 1,2,3)
	ps(numbers)
	
	numbers1 := make([]int, len(numbers), (cap(numbers))*2)
	
	copy(numbers1, numbers)
	ps(numbers)
}

func ps(x []int) {
	fmt.Printf("len=%d cap=%d slice=%v\n", len(x), cap(x), x)
}