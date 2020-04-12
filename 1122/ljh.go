import (
    "fmt"
    "sort"
)
func relativeSortArray(arr1 []int, arr2 []int) []int {
    
    counter := make(map[int]int)
    var front []int
    var back []int
    for _, v := range arr1 {
        counter[v]++
    }
    
    for _, v := range arr2 {
        for counter[v]!=0 {
            front = append(front,v)
            counter[v]--
        }
    }    
    
    for k, v := range counter {
        for v!=0 {
            back = append(back, k)
            v--
        }
    }
    sort.Ints(back)
    
    return append(front, back...)
}
