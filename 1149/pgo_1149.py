n = int(input())

matrix = [[0]*3 for i in range(n)]
matrix2 = matrix.copy()

for i in range(n):
    matrix[i][0], matrix[i][1], matrix[i][2] = map(int, input().split())

#print(matrix)


for i in range(n):
    if i == 0:
        matrix2[i] = matrix[i]

    else:
        matrix2[i][0] = matrix[i][0] + min(matrix2[i-1][1], matrix2[i-1][2]) # R
        matrix2[i][1] = matrix[i][1] + min(matrix2[i-1][0], matrix2[i-1][2]) # G
        matrix2[i][2] = matrix[i][2] + min(matrix2[i-1][0], matrix2[i-1][1]) # B

#print(matrix2)

print(min(min(matrix2[n-1][0], matrix2[n-1][1]), matrix2[n-1][2]))
