func generate(numRows int) [][]int {
    var res [][]int
    if numRows == 0 {
        return res
    }
    row := []int{1}
    res = append(res, row)

    for i:=0;i<numRows-1;i++ {
        temp := []int{1}
        for j:=0;j<len(row);j++ {
            if j + 1 == len(row) {
                break
            }
            temp = append(temp, row[j] + row[j+1])
        }
        temp = append(temp, 1)
        row = temp
        res = append(res, row)
    }
    return res
}

