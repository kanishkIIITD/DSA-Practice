class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int element1, element2;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count1 == 0 && element2 != nums[i]){
                count1++;
                element1 = nums[i];
            }
            else if(count2 == 0 && element1 != nums[i]){
                count2++;
                element2 = nums[i];
            }
            else if(element1 == nums[i]){
                count1++;
            }
            else if(element2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == element1)
                cnt1++;
            if(nums[i] == element2)
                cnt2++;
        }
        if(element1 == element2)
            return {element1};
        if(cnt1++ > floor(n/3))
            ans.push_back(element1);
        if(cnt2++ > floor(n/3))
            ans.push_back(element2);
        return ans;
    }
};