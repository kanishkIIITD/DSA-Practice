class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            bool even = nums[i] % 2 == 0 ? true : false;
            int count = 0;
            for(int j = i+1; j < nums.size(); j++){
                bool flag = nums[j] % 2 == 1 ? true : false;
                if(flag == even)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};