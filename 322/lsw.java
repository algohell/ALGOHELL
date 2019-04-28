import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] value = new int[amount + 1];

        if (coins.length == 0) {
            return -1;
        } else if (amount == 0) {
            return 0;
        }

        Arrays.sort(coins);
        Arrays.fill(value, Integer.MAX_VALUE);
        value[0] = 0;
        
        for (int i = 1; i < value.length; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i - coins[j] < 0) {
                    break;
                } else if (value[i - coins[j]] != Integer.MAX_VALUE) {
                    value[i] = Math.min(value[i], value[i - coins[j]] + 1);
                }
            }
        }
        
        return value[amount] == Integer.MAX_VALUE ? -1 : value[amount];
    }
}