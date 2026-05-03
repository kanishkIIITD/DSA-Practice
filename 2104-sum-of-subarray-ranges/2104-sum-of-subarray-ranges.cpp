class Solution {
public:
    vector<long long> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<long long> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<long long> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<long long> pse(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<long long> nse = findNSE(arr);
        vector<long long> pse = findPSE(arr);
        long long total = 0;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = total + (right * left * arr[i]);
        }
        return total;
    }
    vector<long long> findNGE(vector<int>& arr){
        int n = arr.size();
        vector<long long> nge(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<long long> findPGE(vector<int>& arr){
        int n = arr.size();
        vector<long long> pge(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<long long> nge = findNGE(arr);
        vector<long long> pge = findPGE(arr);
        long long total = 0;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = total + (right * left * arr[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long smallest = sumSubarrayMins(nums);
        long long largest = sumSubarrayMaxs(nums);
        return largest - smallest;
    }
};