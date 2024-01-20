class Solution {
public:
    
    bool recurDP(int i, int j, string s, string p, vector <vector<int>> & dp)
    {
        
        // if both strings are matched
        if(i>=s.size() && j>=p.size())
        {
            return true;
        }
        
        // if input string is left
        if(j>=p.size())
        {
            return false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // if i & j match or j == '.'
        int match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        
        // when j == '*'
        if(j < p.size()-1 && p[j+1] == '*')
        {
            return dp[i][j] = recurDP(i, j+2, s, p, dp) || (match && recurDP(i+1, j, s, p, dp));
        }
        
        if(match)
        {
            return dp[i][j] = recurDP(i+1, j+1, s, p, dp);
        }
        
        // when does not match
        else 
            return false;
        
    } 
    
    bool isMatch(string s, string p) {
        
        // start from the front & keep checking, it will have three conditions
        // 1. when both are same
        // 2. when there is "."
        // 3. when there is '*' -> will either match or ignore
        
        vector <vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        
        return recurDP(0, 0, s, p, dp);
    
    }
};