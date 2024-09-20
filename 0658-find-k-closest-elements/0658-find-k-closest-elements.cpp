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
        return vector<int>(arr.begin()+low, arr.begin()+high+1);
    }
    vector<int> binarySearchMethod(vector<int>& arr, int k, int x){
        int s = 0;
        int e = arr.size()-1;
        int high = e;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] >= x){
                high = m;
                e = m-1;
            }
            else if(x > arr[m])
                s = m+1;
            else 
                e = m-1;
        }

        int low = high-1;
        while(k--){
            if(low < 0)
                high++;
            else if(high >= arr.size())
                low--;
            else if(x-arr[low] > arr[high]-x)
                high++;
            else 
                low--;
        }

        return vector<int>(arr.begin()+low+1, arr.begin()+high);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return twoPointerMethod(arr, k, x);
        return binarySearchMethod(arr, k, x);
    }
};