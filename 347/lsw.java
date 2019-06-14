import java.util.*;

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int value : nums) {
            map.put(value, map.getOrDefault(value, 0) + 1);
        }
    
        PriorityQueue<Integer> pq = new PriorityQueue<>((n1, n2) -> map.get(n1) - map.get(n2));
        
        for (int value : map.keySet()) {
            pq.add(value);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        
        return new ArrayList(pq);
    }
}
