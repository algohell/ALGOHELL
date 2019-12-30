n = 5
st = "3 15 4 12 10"
b = list(map(int,st.split()))

dp = [[0 for _ in range(n)] for _ in range(2)]
# dp[0] : b[i]가 original num일 경우 max값
# dp[1] : b[i]가 1일 경우 max값

for i in range(1,n):
        asdf = input()
        dp[0][i] = max(dp[1][i-1] + abs(b[i]-1), dp[0][i-1] + abs(b[i]-b[i-1]))
        dp[1][i] = max(dp[1][i-1] + (1-1), dp[0][i-1] + abs(1-b[i-1]))
        for d in dp:
                print(d)
print(max(dp[0][-1],dp[1][-1]))
