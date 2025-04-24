class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for(int i = 0; i < arr.size(); i++){
        //     if(arr[i] > k)
        //         return k;
        //     else
        //         k++;
        // }
        // return k;

        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] - mid - 1 < k)
                low = mid+1;
            else
                high = mid-1;
        }
        if (high == -1) return k;
        int x = arr[high] - high - 1;
        int temp = arr[high];
        while(k > x){
            x++;
            temp++;
        }
        return temp;
    }
};