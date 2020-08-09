package main

import "fmt"

var test = map[int][]int{}

func main() {
    var m = [][]int{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
    }
    num := findCircleNum(m)
    fmt.Println(num)
}

func findCircleNum(edges [][]int) int {
    visited := make(map[int]bool)
    groups := 0

    for i := 0; i < len(edges); i++ {
        if !visited[i] {
            groups++
            dfs(visited, edges, i)
        }
    }
    fmt.Println(test)
    return groups
}

func dfs(visited map[int]bool, edges [][]int, i int) {
    if visited[i] {
        return
    }

    visited[i] = true

    for j, f := range edges[i] {
        if f == 1 && !visited[j] {
            dfs(visited, edges, j)
        } else if f == 1 && visited[j] {
            test[i] = append(test[i], j)
        }
    }
}
