class StockSpanner {
public:
    vector<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        int i = st.size()-1;
        while(i >= 0 && st[i] <= price){
            i--;
            count++;
        }
        st.push_back(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */