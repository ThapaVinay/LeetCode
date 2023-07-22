class Solution {
public:
    
    
    // memoization
//     int climbDp(vector <int>& cost, int index, vector <int> & dp)
//     {
//         if(index >= cost.size())
//         {
//             return 0;
//         }
        
//         if(dp[index] != -1)
//         {
//             return dp[index];
//         }
        
//         // 1 step
//         int take = cost[index] + climbDp(cost, index+1, dp);
        
//         // 2 step
//         int not_take = cost[index] + climbDp(cost, index+2, dp);
        
//         dp[index] = min(take, not_take);
//         return dp[index];
//     }
    
    
    // tabular
    int climbDp(vector <int>& cost)
    {
        int n = cost.size();
        vector <int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i= 2; i<n; i++)
        {
            dp[i] = min((cost[i] + dp[i-1]), (cost[i] + dp[i-2]));
        }
        
        return min(dp[n-1], dp[n-2]);
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector <int> dp(n,-1);
        // return min(climbDp(cost, 0,dp), climbDp(cost,1, dp));
        return climbDp(cost);
    }
};