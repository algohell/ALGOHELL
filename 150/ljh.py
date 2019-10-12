import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t == "+":
                n1 = int(stack.pop())
                n2 = int(stack.pop())
                stack.append(n2 + n1)
            elif t == "-":
                n1 = int(stack.pop())
                n2 = int(stack.pop())
                stack.append(n2 - n1)
            elif t == "/":
                n1 = int(stack.pop())
                n2 = int(stack.pop())
                stack.append(math.trunc(n2 / n1))
            elif t == "*":
                n1 = int(stack.pop())
                n2 = int(stack.pop())
                stack.append(n2 * n1)
            else:
                stack.append(t)
        return stack[0]