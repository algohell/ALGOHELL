import java.util.ArrayList;
import java.util.List;

class Solution {
    public int countPrimes(int n) {
        int answer = 0;
        boolean[] nonPrimes = new boolean[n];
        
        for (int num = 2; num < n; num++) {
            if (!nonPrimes[num]) {
                answer++;
                for (int i = 1; i * num < n; i++) {
                    nonPrimes[i * num] = true;
                }
            }
        }
        
        return answer;
    }
}
