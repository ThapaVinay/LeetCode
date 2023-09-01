class Solution {
public:
    
    int countDP(int n, vector <int> &dp)
    {
        if(n == 0)
        {
            return 0;
        }
        
        if(dp[n] != -1)
            return dp[n];
        
        int a;
        if(n % 2 == 1)
            a = 1 + countDP(n/2, dp);
        
        else if(n % 2 == 0)
            a = countDP(n/2, dp);
        
        dp[n] = a;
        return dp[n];
 
    }
    
    
    vector<int> countBits(int n) {
        
        vector <int> res(n+1);
        vector <int> dp(n+1, -1);
        
        res[0] = 0;
        for(int i=1; i<=n; i++)
        {
            res[i] = countDP(i, dp);
        }
        return res;
    }
};