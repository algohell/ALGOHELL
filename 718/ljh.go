func findLength(A []int, B []int) int {
    maxSub := 0
    
    M := make([][]int, 0)
    for i:=0;i<len(A)+1;i++ {
        n := make([]int, len(B)+1)
        M = append(M, n)
    }
    
    for i:=1;i<=len(A);i++ {
        for j:=1;j<=len(B);j++ {
            if A[i-1] == B[j-1] {
                M[i][j] = M[i-1][j-1] + 1
                if M[i][j] > maxSub {
                    maxSub = M[i][j]
                }
            }
        }
    }
    
    return maxSub
}
