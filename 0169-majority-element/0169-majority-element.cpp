class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                element = nums[i];
                count++;
            }
            else if(element == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                ans++;
                if(ans > n/2)
                    return element;
            }
        }
        return -1;
    }
};