func getKth(lo int, hi int, k int) int {
    power := make(map[int]int)
    for i:=lo;i<=hi;i++{
        num := i
        cnt := 0
        for num != 1 {
            if num % 2 == 0 {
                num = num / 2
            } else {
                num = 3 * num + 1
            }
            cnt += 1
        }
        power[i] = cnt
    }

    type kv struct {
        Key   int
        Value int
    }

    var ss []kv
    for k, v := range power {
        ss = append(ss, kv{k, v})
    }

    sort.Slice(ss, func(i, j int) bool {
        if ss[i].Value == ss[j].Value {
             return ss[i].Key < ss[j].Key
        }
        return ss[i].Value < ss[j].Value
    })

    return ss[k-1].Key
}

