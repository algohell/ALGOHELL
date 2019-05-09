import java.util.HashMap;

class Solution {
    public int singleNumber(int[] nums) {
        int answer = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int value : nums) {
            if (map.containsKey(value)) {
                map.put(value, map.get(value) + 1);
                continue;
            }
            map.put(value, 1);
        }
        for (int value : map.keySet()) {
            if (map.get(value) == 1) {
                answer = value;
                break;
            }
        }

        return answer;
    }
}