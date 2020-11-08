func rotateString(A string, B string) bool {
    Abyte := []byte(A)
    for {
        if string(Abyte) == B {
            return true
        }
        if len(Abyte) > 0 {
            Abyte = append(Abyte[1:], Abyte[0])
        }
        if string(Abyte) == A {
            break
        }
    }
    return false
}

