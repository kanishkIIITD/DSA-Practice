class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int totalSize = n + m;
        int ind2 = totalSize/2;
        int ind1 = totalSize/2 - 1;
        int i = 0;
        int j = 0;
        int count = 0;
        int ele1 = -1, ele2 = -1;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                if(count == ind1)
                    ele1 = nums1[i];
                if(count == ind2)
                    ele2 = nums1[i];
                count++;
                i++;
            }
            else{
                if(count == ind1)
                    ele1 = nums2[j];
                if(count == ind2)
                    ele2 = nums2[j];
                count++;
                j++;
            }
        }
        while(i < n){
            if(count == ind1)
                    ele1 = nums1[i];
            if(count == ind2)
                ele2 = nums1[i];
            count++;
            i++;
        }
        while(j < m){
            if(count == ind1)
                ele1 = nums2[j];
            if(count == ind2)
                ele2 = nums2[j];
            count++;
            j++;
        }
        if(totalSize % 2 == 0){
            return (double)(ele1 + ele2) / 2;
        }
        else
            return (double)ele2;
    }
};