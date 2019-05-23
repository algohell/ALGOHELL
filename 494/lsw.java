class Solution {
    private int answer = 0;

    public int findTargetSumWays(int[] nums, int S) {
        bruteForce(nums, 0, 0, S);
        return answer;
    }

    public void bruteForce(int[] arr, int index, int sum, int S) {
        if (index == arr.length) {
            if (sum == S) {
                answer++;
            }
        } else {
            bruteForce(arr, index + 1, sum + arr[index], S);
            bruteForce(arr, index + 1, sum - arr[index], S);
        }
    }
}
