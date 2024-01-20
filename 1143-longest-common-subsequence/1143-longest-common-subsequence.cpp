class Solution {
public:
    
    int recurDP(string &a, string &b, int i, int j, vector <vector<int>> &dp)
    {
        if(i == a.size() || j == b.size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int x = 0, y = 0;
        if(a[i] == b[j])
        {
            x = 1 + recurDP(a, b, i+1, j+1, dp);
        }
        else{
            y = max(recurDP(a, b, i+1, j, dp), recurDP(a, b, i, j+1, dp));
        }
        
        return dp[i][j] = max(x, y);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        // if both characters are same then increment i & j
        // if not equal then either increment i or j
        
        vector <vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        
        return recurDP(text1, text2, 0 , 0, dp);
    }
};