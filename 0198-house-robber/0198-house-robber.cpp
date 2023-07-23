class Solution {
public:
    
    int robDP(vector <int> &nums, int index, vector <int> &dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        // rob house
        int rob = nums[index] + robDP(nums, index+2, dp);
        
        // not rob the house
        int not_rob = robDP(nums, index+1, dp);
        
        
        return dp[index] = max(rob, not_rob);
        
    }
    
    
    int rob(vector<int>& nums) {
        
        vector <int> dp (nums.size(), -1);
        return robDP(nums, 0, dp);
    }
};