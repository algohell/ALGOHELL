package main

import "fmt"

func main() {
	nums := []int{1, 2, 1, 3, 2, 5}
	dict := make(map[int]int)

	var temp []int

	for _, val := range nums {
		dict[val] += 1
	}
	for key, val := range dict {
		if val == 1 {
			temp = append(temp, key)
		}
	}
	fmt.Println(temp)
}
