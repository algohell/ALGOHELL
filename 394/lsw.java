import java.util.Stack;

class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ']') {   // ']' 아니면 stack에 push
                stack.push(s.charAt(i));
                continue;
            }

            StringBuilder temp = new StringBuilder();
            while (!stack.isEmpty() && Character.isAlphabetic(stack.peek())) {
            // ']' 만났을 시 그 전의 알파벳들을 stack에서 pop해서 temp에 옮김
                temp.insert(0, stack.pop()); // stack은 FIFO이므로 반대로 담음
            }

            if (!stack.isEmpty()) {   // stack 안의 '[' 삭제
                stack.pop();
            }

            StringBuilder num = new StringBuilder();
            while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
            // '[' 앞에 있을 숫자를 num에 담음
                num.insert(0, stack.pop());
            }

            int count = Integer.parseInt(num.toString());
            StringBuilder result = new StringBuilder();
            for (int idx = 0; idx < count; idx++) {
                result.append(temp.toString());   // count만큼 [] 안의 알파벳들을 반복하여 담음
            }

            for (char c : result.toString().toCharArray()) {
                stack.push(c);    // 변경한 부분을 다시 stack에 담음
            }
        }

        StringBuilder str = new StringBuilder();
        while (!stack.isEmpty()) {
            str.insert(0, stack.pop());
        }

        return str.toString();
    }
}
