class Solution {
    public int hammingDistance(int x, int y) {
        int answer = 0;
        String binaryX = Integer.toBinaryString(x);
        String binaryY = Integer.toBinaryString(y);
        int lenX = binaryX.length(), lenY = binaryY.length();
        boolean xIsLonger = lenX > lenY ? true : false;
        
        if (xIsLonger == true) {
            for (int i = lenY; i <lenX; i++) {
                binaryY = "0" + binaryY;
                lenY++;
            }
        } else {
            for (int i = lenX; i <lenY; i++) {
                binaryX = "0" + binaryX;
                lenX++;
            }
        }
        
        for (int i = 0; i < lenX && i < lenY; i++) {
            if (binaryX.charAt(i) != binaryY.charAt(i)) {
                answer++;
            }
        }
        
        return answer;
    }
}
