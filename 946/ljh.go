func validateStackSequences(pushed []int, popped []int) bool {
    var stack []int
    for {
        if len(pushed)==0 {
            break
        }
        if len(stack)!=0 && stack[len(stack)-1] == popped[0] {
            stack = stack[:len(stack)-1]
            popped = popped[1:]
        } else if pushed[0] == popped[0] {
            pushed = pushed[1:]
            popped = popped[1:]
        } else {
            stack = append(stack, pushed[0])
            pushed = pushed[1:]
        }
    }
    for _, pop := range popped {
        if stack[len(stack)-1] == pop {
            stack = stack[:len(stack)-1]
        } else {
            break
        }
    }
    return len(stack) == 0
}
