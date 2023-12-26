class Solution {
public:
    
    // vector<int> temp;
    long MOD = 1e9 + 7;
    
    
    long recuDP(int n, int k, int target, int s, vector <vector <int>> &dp)
    {
        if(s == n)
        {
            return (target == 0) ? 1 : 0;
        }
        
        if(target < 0)
        {
            return 0;
        }
        
        if(dp[s][target] != -1)
        {
            return dp[s][target] % MOD;
        }
        
        int res = 0;
        for(int i=1; i<=k; i++)
        {
             res = (res + recuDP(n, k, target - i, s + 1, dp)) % MOD;
        }
        
        return dp[s][target] = res % MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector <vector <int>> dp(n+1, vector <int>(target+1, -1));
        return recuDP(n, k, target, 0, dp);
    }
};