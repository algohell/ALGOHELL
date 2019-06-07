import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> answer = new ArrayList<>();
        // interval 안의 배열에서 첫번째 값을 기준으로 오름차순
        Arrays.sort(intervals, (arr1, arr2) -> arr1[0] - arr2[0]);
        
        for (int[] arr : intervals) {
            int last = answer.size() - 1;
            // 첫번째 값을 기준으로 오름차순 정렬이기에 answer의 마지막 배열의 두번째 값만 보면 됨
            if (last >= 0 && arr[0] <= answer.get(last)[1]) {
                if (answer.get(last)[1] < arr[1]) {
                    answer.get(last)[1] = arr[1];
                }
            } else {
                answer.add(arr);
            }
        }
        
        return answer.toArray(new int[answer.size()][2]);
    }
}