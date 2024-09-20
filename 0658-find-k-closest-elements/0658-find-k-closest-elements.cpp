class Solution {
public:
    vector<int> twoPointerMethod(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high - low >= k){
            if(x-arr[low] > arr[high]-x)
                low++;
            else 
                high--;
        }
        // return {arr.begin()+low, arr.begin()+high+1};
        // vector<int> ans;
        // for(int i = low; i <= high; i++)
        //     ans.push_back(arr[i]);
        // return ans;
        return vector<int>(arr.begin()+low, arr.begin()+high+1);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointerMethod(arr, k, x);
    }
};