func makeGood(s string) string {
    q := make([]byte, 0)
    for _, c := range s {
        if len(q) != 0 && q[len(q)-1] != byte(c) && strings.ToLower(string(q[len(q)-1])) == strings.ToLower(string(c)){
            q = q[:len(q)-1]
        } else {
            q = append(q, byte(c))
        }
    }
    return string(q)
}

