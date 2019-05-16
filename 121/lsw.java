class Solution {
    public int maxProfit(int[] prices) {
        int buy = Integer.MAX_VALUE, sell = Integer.MIN_VALUE, answer = 0;

        if (prices.length == 0) {
            return 0;
        }

        for (int i = 0; i < prices.length; i++) {
            if (buy > prices[i]) {	// buy가 price보다 크면
                buy = prices[i];	// buy을 바꿈
                sell = Integer.MIN_VALUE;	 // sell을 초기화
            }
            sell = Math.max(sell, prices[i]);
            answer = Math.max(answer, sell - buy);
        }

        return answer;
    }
}