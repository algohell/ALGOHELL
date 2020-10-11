func findTheDifference(s string, t string) byte {
    sMap := make(map[rune]int)
    for _, r := range s {
        sMap[r] += 1
    }
    for _, r := range t {
        if _, ok := sMap[r]; ok {
            sMap[r] -= 1
            if sMap[r] < 0 {
                return byte(r)
            }
        } else {
            return byte(r)
        }
    }
    return 0
}

