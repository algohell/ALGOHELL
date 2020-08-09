package main

func lemonadeChange(bills []int) bool {
    change := map[int]int{
        5: 0,
        10: 0,
        20: 0,
    }

    for _, bill := range bills {
        change[bill] += 1
        if bill == 10 {
            if change[5] > 0 {
                change[5] -= 1
            } else {
                return false
            }
        } else if bill == 20 {
            if change[10] > 0 && change[5] > 0{
                change[5] -= 1
                change[10] -= 1
            } else if change[5] >= 3 {
                change[5] -= 3
            }  else {
                return false
            }
        }
    }
    return true
}
