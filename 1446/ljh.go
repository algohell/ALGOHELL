func maxPower(s string) int {
    bytes := []byte(s)
    temp := bytes[0]
    cnt := 0
    maxCnt := 1

    for _, b := range bytes {
        if b == temp {
            cnt += 1
        } else {
            temp = b
            cnt = 1
        }
        if cnt > maxCnt {
            maxCnt = cnt
        }
    }

    return maxCnt
}

