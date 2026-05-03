class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int total = 0;
        long long MOD = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % MOD) % MOD;
        }
        return total;
    }
};