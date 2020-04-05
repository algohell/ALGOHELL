class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = 0
        ten = 0
        
        for b_i in bills:
            if b_i == 5:
                five += 1

            elif b_i == 10:
                if not five:
                    return False
                five -= 1
                ten += 1

            else:  # 20
                if not ten:
                    if five < 3: # 15
                        return False
                    five -= 3
                if ten:
                    if not five:
                        return False
                    five -= 1
                    ten -= 1

        return True
