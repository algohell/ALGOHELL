package main

import (
	"fmt"
)

func dfs(res *[][]int, nums []int, cnt int) {
	if cnt == len(nums) {
		temp := make([]int, len(nums))
		copy(temp, nums)
		*res = append(*res, temp)
	}
	for i := cnt; i < len(nums); i++ {
		nums[i], nums[cnt] = nums[cnt], nums[i]
		dfs(res, nums, cnt+1)
		nums[cnt], nums[i] = nums[i], nums[cnt]
	}
}

func main() {
	nums := []int{1, 2, 3}
	var res [][]int
	dfs(&res, nums, 0)

	fmt.Println(res, len(res))
}
