class Solution {
public:
    
    int MOD = 1e9 + 7;
    
    int solveDP(int n, int m, int prev, int k, vector <vector< vector<int>>> & dp)
    {
        if(n == 0)
        {
            if(k == 0)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[n][prev][k] != -1)
        {
            return dp[n][prev][k];
        }
        
        int ans = 0;
        for(int i=1; i<=m; i++)
        {
            if(i > prev && k > 0)
            {
                ans = (ans + solveDP(n-1,m,i,k-1, dp) ) % MOD;
            }
            else if(i <= prev)
            {
                ans  = (ans + solveDP(n-1,m,prev,k, dp) ) % MOD;
            }
            
        }
        
        return dp[n][prev][k] = ans%MOD;
    }
    
    int numOfArrays(int n, int m, int k) {
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1, vector<int>(k+1,-1)));
        
        return solveDP(n, m, 0, k, dp);

    }
};