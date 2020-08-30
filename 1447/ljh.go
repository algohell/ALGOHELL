func simplifiedFractions(n int) []string {
    var result []string
    for i:=n;i>1;i-- {
        for j:=1;j<i;j++ {
            IsSimplified(i, j, &result)
        }
    }
    return result
}

func IsSimplified(i, j int, result *[]string) {
    check := true
    for k:=2;k<=j;k++ {
        if i % k == 0 && j % k == 0 {
            check = false
            break
        }
    }
    if check {
        *result = append(*result, strconv.Itoa(j) + "/" + strconv.Itoa(i))
    }
}

