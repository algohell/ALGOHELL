import java.util.HashSet;

class Solution {
    public int findDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        int answer = 0;
        
        for (int value : nums) {
            if (set.contains(value)) {
                answer = value;
                break;
            } else {
                set.add(value);
            }
        }
        
        return answer;
    }
}