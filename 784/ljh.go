func letterCasePermutation(S string) []string {
    var res = []string{S}
    FullSearch([]byte(S), 0, &res)

    return res
}

func FullSearch(S []byte , idx int, res *[]string) {
    if idx == len(S) {
        return
    }

    if S[idx] > 57 {
        // pass
        FullSearch(S, idx+1, res)

        // change
        if S[idx] >= 65 && S[idx] <= 90 {
            S[idx] += 32
            *res = append(*res, string(S))
        } else if S[idx] >= 97 && S[idx] <= 122 {
            S[idx] -= 32
            *res = append(*res, string(S))
        }
        FullSearch(S, idx+1, res)
    } else {
        FullSearch(S, idx+1, res)
    }
}

