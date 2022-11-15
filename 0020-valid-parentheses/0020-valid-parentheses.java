class Solution {
    public boolean isValid(String st) {
        Stack<Character> s = new Stack<>();
        
        for(int i = 0; i<st.length(); i++){
            char ch = st.charAt(i);
            if(ch == '(' || ch == '[' || ch == '{'){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char top = s.peek();
                    if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')){
                        s.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            } 
        }
        if(s.empty())
            return true;
        else
            return false;
    }
}