class MinStack {
private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long valLL = val;
        if(st.empty()){
            mini = valLL;
            st.push(valLL);
        }
        else if(valLL < mini){
            st.push(2 * valLL - mini);
            mini = valLL;
        }
        else
            st.push(valLL);
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top() > mini)
            st.pop();
        else{
            mini = 2 * mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top() > mini)
            return (int)st.top();
        else{
            return (int)mini;
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */