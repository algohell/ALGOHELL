package main

import (
    "fmt"
    "strings"
)

func main() {
    fmt.Println(minRemoveToMakeValid("))(("))
}
func minRemoveToMakeValid(s string) string {
    var stack []int
    var bytes = []byte(s)

    for i, b := range bytes {
        if b == '(' {
            stack = append(stack, i)
        } else if b == ')' {
            if len(stack) > 0 {
                stack = stack[:len(stack)-1]
            } else {
                bytes[i] = '0'
            }
        }
    }

    for len(stack) > 0 {
       bytes[stack[len(stack)-1]] = '0'
       stack = stack[:len(stack)-1]
    }

    return strings.ReplaceAll(string(bytes), "0", "")
}