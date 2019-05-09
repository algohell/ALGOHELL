import java.util.List;
import java.util.ArrayList;

class Solution {
    String[] num = {null, null, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public List<String> letterCombinations(String digits) {
        List<String> digitStr = new ArrayList<>();
        List<String> preCase = new ArrayList<>();
        List<String> postCase = new ArrayList<>();

        if (digits.length() == 0) {
            return preCase;
        }

        for (char c : digits.toCharArray()) {
	// digitStr에 digits에 해당하는 문자들을 담는다
            int i = c - '0';
            digitStr.add(num[i]);
        }

        for (char c : digitStr.get(0).toCharArray()) {
            preCase.add(String.valueOf(c));
	// preCase에 digit의 첫번째 숫자에 해당하는 문자들을 담는다
        }
        digitStr.remove(0);

        for (String str : digitStr) {
            for (char c : str.toCharArray()) {
                for (String s : preCase) {
                    StringBuilder builder = new StringBuilder(s);
                    builder.append(c);
                    postCase.add(builder.toString());
	       // preCase에서 다음 번호들에 해당하는 문자를 더한 것을 postCase에 담는다
                }
            }
            preCase.clear();
            preCase.addAll(postCase);	// postCase의 값들을 모두 preCase로
            postCase.clear();
        }
        
        return preCase;
    }
}