func findJudge(N int, trust [][]int) int {
    if N == 1 {
        return 1
    }
    trustMap := make(map[int][]int)
    trustedMap := make(map[int][]int)
    for _, t := range trust {
        trustMap[t[0]] = append(trustMap[t[0]], t[1])
        trustedMap[t[1]] = append(trustedMap[t[1]], t[0])
    }

    allTrusted := make([]int, 0)
    for k, v := range trustedMap {
        if len(v) == N-1 {
            allTrusted = append(allTrusted, k)
        }
    }
    
    for _, a := range allTrusted {
        if _, ok := trustMap[a]; !ok {
            return a
        }
    }
    return -1
}
