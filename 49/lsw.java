import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>();
        int check;

        if (strs.length == 0) {
            return answer;
        }

        for (String value : strs) {
            char[] arr1 = value.toCharArray();
            Arrays.sort(arr1);
            String order1 = String.valueOf(arr1);
            check = 0;
            for (List list : answer) {
                if (list.size() > 0) {
                    String order2 = list.get(0).toString();
                    if (order1.equals(order2)) { // list의 첫번째 값과 비교
                        list.add(value);
                        check = 1; // 이미 리스트가 존재하는지 여부 확인
                        break;
                    }
                }
            }
            if (check != 1) {
                List<String> temp = new ArrayList<>();
                temp.add(order1); // 정렬된 값을 리스트의 첫번째 값으로
                temp.add(value);
                answer.add(temp);
            }
        }
        for (List list : answer) {
            list.remove(0); // 비교를 위해 추가한 정렬된 값 제거
        }

        return answer;
    }
}