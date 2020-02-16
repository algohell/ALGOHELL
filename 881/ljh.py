people = [5,1,4,2]
limit = 6

pw = sorted(people)
l, r = 0, len(pw)-1
boat = 0
while r <= l:
    boat += 1
    if pw[l] + pw[r] <= limit:
        l += 1
    r -= 1

    