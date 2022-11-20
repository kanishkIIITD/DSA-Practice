class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> s = new Stack<>();
        int j = 0;
        
        for(int i = 0; i < pushed.length; i++){
            s.push(pushed[i]);
            
            while(!s.isEmpty() && s.peek() == popped[j]){
                s.pop();
                j++;
            }
        }
        
        if(s.isEmpty())
            return true;
        else
            return false;
    }
}