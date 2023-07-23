class Solution {
public:
    
    int robDP(vector <int>& nums, int index, int last, vector<int> &dp)
    {
        if(index == last)
        {
            return nums[last];

        }
        
        if(index > last)
        {
            return 0;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        // take
        int take = nums[index] + robDP(nums, index+2, last, dp);
        
        // not_take
        int not_take = robDP(nums, index+1,last, dp);
        
        return dp[index] = max(take, not_take);
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp (n,-1);
        vector <int> dp1 (n,-1);
        
        if(n == 1)
        {
            return nums[0];
        }
        int val1 = robDP(nums, 0,n-2,dp); 
        int val2 = robDP(nums, 1, n-1, dp1);

        
        return max(val1, val2);
    }
};