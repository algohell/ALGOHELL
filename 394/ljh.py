import re
class Solution(object):
  def decodeString(self, s):
    stack = []
    repeats = 0
    digits = set("0123456789")

    for c in s:
      if c == "]":
        item = stack.pop()
        #print("item",item)
        current = []
        while not isinstance(item, int):
          current.append(item)
          item = stack.pop()
        #print(current[::-1])
        stack += (current[::-1] * item)
      elif c in digits:
        repeats = repeats * 10 + int(c)
        #print("rep",repeats)
      elif c == "[":
        stack.append(repeats)
        #print(stack)
        repeats = 0
      else:
        stack.append(c)

    return "".join(stack)

sol=Solution()
s = "3[a]2[bc]"
print(sol.decodeString(s))



