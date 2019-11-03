T = int(input())
case = [input() for _ in range(T)]

def vps_check(c):
  stack = []
  for i in range(len(c)):
    if c[i]=="(":
      stack.append("(")
    elif c[i]==")":
      if stack:
        stack.pop()
      else: 
        return "NO"
  if stack:
    return "NO"
  else:
    return "YES"

for c in case:
  print(vps_check(c))