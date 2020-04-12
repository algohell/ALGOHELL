import (
	"fmt"
	"sort"
)

func groupAnagrams(strs []string) [][]string {
	var res [][]string
	dict := make(map[string][]string)

	for _, w := range strs {
		runes := []rune(w)
		sort.Slice(runes, func(a, b int) bool { return runes[a] < runes[b] })
		sortedWord := string(runes)
		dict[sortedWord] = append(dict[sortedWord], w)
	}

	for _, v := range dict {
		res = append(res, v)
	}

	return res
}