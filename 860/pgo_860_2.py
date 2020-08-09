class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        f = 0
        t = 0

        for b_i in bills:
            if b_i == 5:
                f += 1

            elif b_i == 10:
                if not f:
                    return False
                f -= 1
                t += 1

            else:
                if not t:
                    if f < 3:
                        return False
                    f -= 3
                else:
                    if not f:
                        return False
                    f -= 1
                    t -= 1

        return True