class Solution {
public:
    
    int integerDP(int n, vector<int> &dp)
    {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return -1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int res = 1;
        for(int i=2; i<n; i++)
        {
            res = max(res, i * integerDP(n-i, dp));
        }
        return dp[n] = res;
    }
    
    int integerBreak(int n) {
        if(n <= 3)
            return --n;
        
        vector<int> dp(n+2, -1);
        
        return integerDP(++n, dp);
    }
};