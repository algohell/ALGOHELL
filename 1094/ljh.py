from collections import defaultdict

trips = [[3,2,7],[3,7,9],[8,3,9]]
capacity = 11

def carPooling(tirps, capacity):
    d = defaultdict(int)
    for t in trips:
        for i in range(t[1],t[2]):
            d[i] += t[0]
            if d[i] > capacity:
                return False
    return True

print(carPooling(trips,capacity))