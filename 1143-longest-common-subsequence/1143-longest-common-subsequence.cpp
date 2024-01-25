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
    
    
    
    int recurTab(string &text1, string &text2)
    {
        vector <vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        
        for(int i=text1.size()-1; i>=0; i--)
        {
            for(int j=text2.size()-1; j>=0; j--)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
    
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        // if both characters are same then increment i & j
        // if not equal then either increment i or j
        
        // vector <vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        
        // return recurDP(text1, text2, 0 , 0, dp);
        
        return recurTab(text1, text2);
    }
};