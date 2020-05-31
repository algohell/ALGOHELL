func minFallingPathSum(A [][]int) int {
    dp := make([][]int,len(A))
    dp[0] = A[0]
    for i:=1;i<len(A);i++ {
        for j:=0;j<len(A);j++{
            dp[i] = append(dp[i], -101)
        }
    }

    for h:=1;h<len(A);h++ {
        for w:=0;w<len(A);w++ {
            for j:=-1;j<2;j++{
                if (w+j)>=0 && (w+j)<len(A) {
                    if dp[h][w+j]==-101{
                        dp[h][w+j] = dp[h-1][w] + A[h][w+j]
                    } else if dp[h-1][w] + A[h][w+j] < dp[h][w+j] {
                        dp[h][w+j] = dp[h-1][w] + A[h][w+j]
                    }
                }
            }
        }
    }

    min := 101
    for i:=0;i<len(A);i++ {
        if min > dp[len(A)-1][i] {
            min = dp[len(A)-1][i]
        }
    }

    return min
}
