class Solution {
public:
    
    // tabular
    int solveTab(vector <int> &nums, int t)
    {
        vector <uint> dp(t+1);
        
        dp[0] = 1;
        
        for(int i=1; i<=t; i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if(i-nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[t];
    }
    
    
    
    // memoization
    int solveDP(vector<int> &nums, int t, vector <int> &dp)
    {
        if(t == 0)
        {
            return 1;
        }
        
        if(t < 0)
        {
            return 0;
        }
        
        if(dp[t] != -1)
        {
            return dp[t];
        }
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += solveDP(nums, t- nums[i], dp);
        }
        
        return dp[t] = ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        // vector <int> dp (target+1, -1);
        // return solveDP(nums, target, dp);
        
        return solveTab(nums, target);
    }
};