class Solution {
public:
    
    bool recurDP(vector<int> &nums, int i, vector <int> &dp)
    {
        if(i == nums.size()-1)
            return true;
        
        if(i >= nums.size())
            return false;
        
        if(dp[i] != -1)
        {
            return dp[i];
        }
        
        bool flag = false;
        for(int j=1; j<=nums[i]; j++)
        {
            flag = flag || recurDP(nums, i+j, dp);
            if(flag)
                return dp[i] = flag;
        }
        return dp[i] = flag;
    }
    
    bool canJump(vector<int>& nums) {
        
        vector <int> dp(nums.size(), -1);
        return recurDP(nums, 0, dp);
        
    }
};