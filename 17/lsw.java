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
	// digitStr�� digits�� �ش��ϴ� ���ڵ��� ��´�
            int i = c - '0';
            digitStr.add(num[i]);
        }

        for (char c : digitStr.get(0).toCharArray()) {
            preCase.add(String.valueOf(c));
	// preCase�� digit�� ù��° ���ڿ� �ش��ϴ� ���ڵ��� ��´�
        }
        digitStr.remove(0);

        for (String str : digitStr) {
            for (char c : str.toCharArray()) {
                for (String s : preCase) {
                    StringBuilder builder = new StringBuilder(s);
                    builder.append(c);
                    postCase.add(builder.toString());
	       // preCase���� ���� ��ȣ�鿡 �ش��ϴ� ���ڸ� ���� ���� postCase�� ��´�
                }
            }
            preCase.clear();
            preCase.addAll(postCase);	// postCase�� ������ ��� preCase��
            postCase.clear();
        }
        
        return preCase;
    }
}