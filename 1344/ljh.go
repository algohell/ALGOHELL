package main

import "math"

func angleClock(hour int, minutes int) float64 {
    hourd := float64(30)  * (float64(minutes*6)/float64(360))
    degree := math.Abs((float64(hour * 30) + hourd) - float64(minutes*6))
    if reverse := 360.0 - degree; reverse < degree {
        degree = reverse
    }

    return degree
}
