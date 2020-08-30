func findContentChildren(g []int, s []int) int {
    var res = 0
    sort.Ints(g)
    sort.Ints(s)
    for i:=0;i<len(g);i++ {
        for j:=0;j<len(s);j++ {
            if s[j] >= g[i] {
                res++
                s = append(s[:j], s[j+1:]...)
                break
            }
        }
    }
    return res
}

