public class Solution {
    char[] right = {')', '}', ']'};
    String left = "({[";
    public boolean isValid(String s) {
        int[] stack = new int[s.length()];
        int head = 0; 
        for(char c : s.toCharArray()) {
            int rIdx = left.indexOf(c);
            if(rIdx != -1) {
                stack[head++] = rIdx;
                continue;
            }
            if (head == 0 || c != right[stack[--head]]) {
                return false;
            }
        }
        return head == 0;
    }
}