func minStartValue(nums []int) int {
    
    start := 1
    check := false
    for !check {
        check = true
        sum := start
        for _, n := range nums {
            sum += n
            if sum < 1 {
                check = false
                break
            }
        }
        if !check {
            start += 1
        }
    }
    
    return start
}

