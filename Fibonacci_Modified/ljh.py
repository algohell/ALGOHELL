a1,a2,nth = map(int,input().split())

F = [a1,a2]
for i in range(2,nth):
    F.append(F[i-2] + (F[i-1]**2))
    print(F)

print(F[-1])