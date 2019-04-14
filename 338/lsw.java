class Solution {
    public int[] countBits(int num) {
        int[] answer = new int[num + 1];
        int power = 2;

        if (num == 0) {
            return answer;
        }

        answer[1] = 1;
        for (int i = 2; i <= num; i++) {
            if (i % power == 0) {           // 2의 n승일 경우 1의 개수는 1개
                answer[i] = 1;
                power *= 2;
            } else {
                answer[i] = answer[power / 2] + answer[i - (power / 2)];            // i.g. answer[12] = answer[8] + answer[4] = 2
            }
        }

        return answer;
    }
}
