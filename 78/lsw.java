import java.util.ArrayList;
import java.util.List;
import java.util.Set;

class Solution {
    
    static List<List<Integer>> answer;
    
    public List<List<Integer>> subsets(int[] nums) {
        answer = new ArrayList<>();
        answer.add(new ArrayList<Integer>());
        
        for (int i = 0; i < nums.length; i++) {
            makeCase(nums, new ArrayList<Integer>(), i);
        }
        
        return answer;
    }
    
    public void makeCase(int[] nums, List<Integer> list, int index) {
        List<Integer> newList = new ArrayList(list);
        newList.add(nums[index]);
        answer.add(newList);
        
        for (int i = index + 1; i < nums.length; i++) {
            makeCase(nums, newList, i);
        }
    }
}