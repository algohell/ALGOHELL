class Solution {
    public int maxProfit(int[] prices) {
        int buy = Integer.MAX_VALUE, sell = Integer.MIN_VALUE, answer = 0;

        if (prices.length == 0) {
            return 0;
        }

        for (int i = 0; i < prices.length; i++) {
            if (buy > prices[i]) {	// buy�� price���� ũ��
                buy = prices[i];	// buy�� �ٲ�
                sell = Integer.MIN_VALUE;	 // sell�� �ʱ�ȭ
            }
            sell = Math.max(sell, prices[i]);
            answer = Math.max(answer, sell - buy);
        }

        return answer;
    }
}