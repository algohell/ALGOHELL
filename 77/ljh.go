func combine(n int, k int) [][]int {
    res := make([][]int, 0)
    temp := make([]int, 0)
    val := make([]int, n)
    
    for i:=0;i<n;i++ {
        val[i] = i+1
    }

    backtracking(n, k, val, temp, &res)
    return res
}

func backtracking(n int, k int, val []int, temp []int, res *[][]int) {
    fmt.Println(*res)
    fmt.Println(temp)
    if len(temp) == k {
        tempCopy := make([]int, len(temp))
        copy(tempCopy, temp)
        *res = append(*res, tempCopy)
        return
    }
    
    for i:=0;i<len(val);i++ {
        if len(temp) == 0 || temp[len(temp)-1] != val[i] {
            temp = append(temp, val[i])
        }
        backtracking(n, k, val[i+1:], temp, res)
        temp = temp[:len(temp)-1]
    }
    return
}

