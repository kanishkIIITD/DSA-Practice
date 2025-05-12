class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        int i = 0;
        int j = 0;
        while(i < m){
            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                int temp = j;
                while(temp < n-1 && nums2[temp] > nums2[temp+1]){
                    swap(nums2[temp], nums2[temp+1]);
                    temp++;
                }
            }
            i++;
        }
        while(i < m+n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};