#70 : https://leetcode.com/problems/climbing-stairs/
# 피보나치 수열
#n = 13 # stairs
#stairs(n):1, 2, 3, 4, 5,  6,  7, 8
#increase:  1  1  2  3  5   5   6 
#ways:    1, 2, 3, 5, 8, 13, 17, 23 
n = 0

def fibo(n):
    #x = 1
    #y = 2
    #c = 0
    x,y,c = 1,2,0
    
    if n == 0:
        return 0
    
    while c < n-1:
        c += 1
            # x = y
            # y = x+y
        x, y = y, x+y
        return x


def fibo1(n):
    dp = [1 for i in range(n+1)]
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]
    

        

#print(fibo(7))
#print(fibo1(7))