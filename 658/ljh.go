func findClosestElements(arr []int, k int, x int) []int {
    minDiff := math.MaxFloat64
    minIdx := 0
    
    scoreMap := make(map[int]float64)
    
    for i, n := range arr {
        diff := math.Abs(float64(x - n))
        if diff < minDiff {
            minDiff = diff
            minIdx = i
        }
        scoreMap[i] = diff
    }
    
    var frontIdx = minIdx - 1
    var backIdx = minIdx + 1
    
    var res = make([]int, 0)
    res = append(res, arr[minIdx])
    k -= 1
    
    for k > 0 {
        if frontIdx >= 0 && backIdx < len(arr) {
            if scoreMap[frontIdx] <= scoreMap[backIdx] { 
                res = append([]int{arr[frontIdx]}, res...)
                frontIdx--
                k--
            } else {
                res = append(res, arr[backIdx])
                backIdx++
                k--
            }
        } else if frontIdx < 0 && k > 0 {
            res = append(res, arr[backIdx])
            backIdx++
            k--
        } else if backIdx >= len(arr) && k > 0 {
            res = append([]int{arr[frontIdx]}, res...)
            frontIdx--
            k--
        }
    }
    
    return res
}

