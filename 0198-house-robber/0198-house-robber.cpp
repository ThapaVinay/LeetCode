class Solution {
public:
    
    // memoization
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
    
    
    // tabular
    int robTabular(vector <int> &nums)
    {
        vector <int>dp(nums.size()+1,0);
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i=2; i<nums.size(); i++)
        {
            dp[i] = max((nums[i] + dp[i-2]), dp[i-1]);
        }
        
        return dp[nums.size()-1];
    }
    
    
    int rob(vector<int>& nums) {
        
        // vector <int> dp (nums.size(), -1);
        // return robDP(nums, 0, dp);
        
        return robTabular(nums);
    }
};