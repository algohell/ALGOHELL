func maxWidthRamp(A []int) int {
    maxRamp := 0
    type Astruct struct {
        Idx int
        Value int
    }
    
    st := make([]Astruct, 0)
    for i, a := range A {
        st = append(st, Astruct{
            Idx: i,
            Value: a,
        })
    }
    
    sort.Slice(st, func (i, j int) bool {
        if st[i].Value == st[j].Value {
            return st[i].Idx < st[j].Idx
        }
        return st[i].Value < st[j].Value
    })
    
    endVal := make([]Astruct, 0)
    val := st[0].Value
    for i:=0;i<len(st)-1;i++ {
        if st[i+1].Value != val {
            endVal = append(endVal, st[i])
            val = st[i+1].Value
        }
    }
    endVal = append(endVal, st[len(st)-1])
    
    for _, ev := range endVal {
        for _, s := range st {
            if ev.Idx == s.Idx {
                break
            }
            ramp := ev.Idx - s.Idx
            if ramp > maxRamp {
                maxRamp = ramp
            }
        }
    }
    
    
    return maxRamp
}
