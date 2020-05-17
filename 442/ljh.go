import "sort"

func findDuplicates(nums []int) []int {
    sort.Ints(nums)
    res := make([]int, 0)
    for i:=1;i<len(nums);i++ {
        if nums[i-1] == nums[i] {
            res = append(res, nums[i])
        }
    }
    return res
}
