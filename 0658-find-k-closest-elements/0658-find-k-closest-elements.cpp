class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size()-1;
        while(high - low >= k){
            if(x-arr[low] > arr[high]-x)
                low++;
            else 
                high--;
        }
        return {arr.begin()+low, arr.begin()+high+1};
    }
};