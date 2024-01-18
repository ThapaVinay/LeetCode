class Solution {
public:
    
    int recurDP(int n, vector<int> &dp)
    {
        if(n == 0)
            return 1;

        
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        // 1 step
        int a = recurDP(n-1, dp);
        
        // 2 step
        int b = recurDP(n-2, dp);
        
        return dp[n] = a+b;
    }
    
    int climbStairs(int n) {
        
        vector <int> dp (n+1, -1);
        
        return recurDP(n, dp);
    }
};