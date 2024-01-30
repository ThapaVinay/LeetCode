class Solution {
public:
    
    bool recurDP(vector<int> &nums, int m, int i, int j, int sum, vector <vector<int>> &dp)
    {
        if(i >= j)
            return true;
        
        if(sum < m)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // split from start
        int start = recurDP(nums, m, i+1, j, sum - nums[i], dp);
        
        // split from end
        int end = recurDP(nums, m, i, j-1, sum - nums[j], dp);
        
        return dp[i][j] = start || end;
    }
    
    bool canSplitArray(vector<int>& nums, int m) {
        
        // use recursion to either split from start or end
        
        if(nums.size() == 2)
            return true;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];    
        }
        
        // memoisation
        vector <vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        
        return recurDP(nums, m, 0, nums.size()-1, sum, dp);
    }
};