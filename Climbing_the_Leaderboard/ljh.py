import bisect

scores_count = int(input())
scores = list(map(int, input().rstrip().split()))
alice_count = int(input())
alice = list(map(int, input().rstrip().split()))

def climbingLeaderboard(scores, alice):
  scores = sorted(list(set(scores)))
  res = []
  for a in alice:
      res.append((len(scores)+1)-bisect.bisect_right(scores,a))
  return res

print(climbingLeaderboard(scores,alice))