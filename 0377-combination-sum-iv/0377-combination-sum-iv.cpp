class Solution {
public:
    
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
        
        vector <int> dp (target+1, -1);
        return solveDP(nums, target, dp);
    }
};