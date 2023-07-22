class Solution {
public:
    
    int climbDp(vector <int>& cost, int index, vector <int> & dp)
    {
        if(index >= cost.size())
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        // 1 step
        int take = cost[index] + climbDp(cost, index+1, dp);
        
        // 2 step
        int not_take = cost[index] + climbDp(cost, index+2, dp);
        
        dp[index] = min(take, not_take);
        return dp[index];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n,-1);
        return min(climbDp(cost, 0,dp), climbDp(cost,1, dp));
    }
};