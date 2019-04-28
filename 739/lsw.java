class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] answer = new int[T.length];
        for (int i = 0; i < T.length; i++) {
            for (int j = i + 1; j < T.length; j++) {
                if (T[i] < T[j]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
}