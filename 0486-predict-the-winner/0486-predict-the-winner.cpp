class Solution {
public:
    int solve(int index, int lastIndex, int flag, vector<int>&nums){
        if(index > lastIndex)
            return 0;
        if(flag){
            return max(nums[index] + solve(index+1, lastIndex, 0, nums), nums[lastIndex] + solve(index, lastIndex-1, 0, nums));
        }
        else{
            return min(-nums[index] + solve(index+1, lastIndex, 1, nums), -nums[lastIndex] + solve(index, lastIndex-1, 1, nums));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        
        int ans = solve(0, n-1, 1, nums); //{index, lastIndex, flag, nums} flag = 1 mean player1, else player2
        if(ans >= 0)
            return true;
        else    
        return false;
    }
};