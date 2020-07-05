package main

import "fmt"

func main(){
    res := isSubsequence("abc","ahbgdc")
    fmt.Println(res)
}
func isSubsequence(s string, t string) bool {
    for _, c := range t {
        if len(s) == 0 {
            return true
        }
        if c == rune(s[0]) {
            s = s[1:]
        }
    }
    if len(s) == 0 {
        return true
    }
    return false
}
