func singleNumber(nums []int) int {
    counts := make(map[int]int)
    for _, n := range nums {
        counts[n] += 1
    }
    for k, v := range counts {
        if v == 1 {
            return k
        }
    }
    return 0
}
