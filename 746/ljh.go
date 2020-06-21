package main

import (
    "fmt"
    "math"
)

func minCostClimbingStairs(cost []int) int {
    dp := make([]int, len(cost) + 1)
    for i:=2;i<=len(cost);i++ {
        dp[i] = int(math.Min(float64(dp[i-1]+cost[i-1]), float64(dp[i-2]+cost[i-2])))
        fmt.Printf("i: %d, %d + %d, %d + %d, %d\n", i, dp[i-1], cost[i-1], dp[i-2], cost[i-2], dp[i])
    }
    fmt.Println(dp)
    return dp[len(cost)]
}

func main(){
    cost := []int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}
    res := minCostClimbingStairs(cost)
    fmt.Println(res)
}
