class Solution {
public:
    
    int MOD = 1e9+7;
    
    int recurDP(int n, int k, vector <vector<int>> &dp)
    {
        if(n == 0)
            return 0;
        
        if(k == 0)
            return 1;
        
        if(dp[n][k] != -1)
            return dp[n][k] ;
        
        long res = 0;
        
        // you can have k inverse pairs after each element addition
        // and they will not be more than the n-1 elements left
        for(int x=0; x<= min(n-1,k); x++)
        {
            res = (res + recurDP(n-1, k-x, dp)%MOD) %MOD;
        }
        
        return dp[n][k] = (res %MOD);
    }
    
    int kInversePairs(int n, int k) {
        
        // just iterate through k and for each element you have the option that it will make 1, 2, 3 ... k inverse pairs
        
        vector <vector<int>> dp(n+1, vector<int>(k+1, -1));
        return recurDP(n, k, dp);
    }
};