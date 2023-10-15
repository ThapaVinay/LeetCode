class Solution {
public:
    
    int MOD = 1e9 + 7;
    int numRec(int steps, int arr, int i, vector <vector<int>> &dp)
    {
        if(i >= arr || i < 0)
        {
            return 0;
        }

        if(steps == 0 && i == 0)
        {
            return 1;
        }
        else if(steps == 0)
        {
            return 0;
        }
        
        if(dp[steps][i] != -1)
        {
            return dp[steps][i];
        }
        
        long count = 0;
        
        // right
        count += numRec(steps-1, arr, i+1, dp) % MOD;
        
        // left
        count += numRec(steps-1, arr, i-1, dp) % MOD;
        
        // stay
        count += numRec(steps-1, arr, i, dp) % MOD;
        
        return dp[steps][i] = count % MOD;
        
    }
    
    int numWays(int steps, int arrLen) {
        
        vector <vector<int>> dp(501, vector<int>(501, -1));
        
        return numRec(steps, arrLen, 0, dp);
    }
};