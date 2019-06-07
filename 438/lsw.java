import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.stream.IntStream;

class Solution {
    
    static final int ALPABHET_LENGTH = 26;
    
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> answer = new ArrayList<>();
        int len = p.length();
        
        for (int i = 0; i <= s.length() - len; i++) {
            String str = s.substring(i, i + len);
            if (isSame(str, p)) {
                answer.add(i);
            }
        }
        
        return answer;
    }
    
    public boolean isSame(String str, String target) {
        int[] arr = new int[ALPABHET_LENGTH];
        
        for (int i = 0; i < str.length(); i++) {
            arr[str.charAt(i) - 'a']++;
            arr[target.charAt(i) - 'a']--;
        }
        
        for (int value : arr) {
            if (value != 0) {
                return false;
            }
        }
        
        return true;
    }
}
