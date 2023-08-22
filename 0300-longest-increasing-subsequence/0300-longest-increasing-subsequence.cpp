class Solution {
public:
    
    int lengthDP(vector <int> &nums, int i, int j, vector <vector<int>> &dp)
    {
        // base case
        if(i >= nums.size())
        {
            return 0;
        }
        
        if(j != -1 && dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int take = 0;
        if(j == -1 || nums[j] < nums[i])
        {
            // take 
            take = 1 + lengthDP(nums, i+1, i, dp);     
        } 
        int not_take = lengthDP(nums, i+1, j, dp); 
        
        // if(j != -1)
        // {
        //     dp[i][j] = max(take, not_take);
        //     return dp[i][j];
        // }
        
        if(j != -1)
        {
            dp[i][j] = max(take, not_take);
            return dp[i][j];
        }
            
        
        return max(take, not_take);;
    }
    
    
    
    int lengthOfLIS(vector<int>& nums){
        
        // iterate over the array and
        // take a particular value or not take considering it follows the increasing sequence
        
        vector <vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return lengthDP(nums,0, -1, dp);
    }
};