class Solution {
public:
    
    int recurDP(vector <int> &n, vector <int> &m, int i, int j, int x, vector <vector<int>> &dp)
    {
        if(i > j || x == m.size())
            return 0;
        
        if(dp[i][x] != -1)
            return dp[i][x];
        
        // select from last
        int last = m[x] * n[j] + recurDP(n, m, i, j-1, x+1, dp);
        
        // select from start
        int start =  m[x] * n[i] + recurDP(n, m, i+1, j, x+1, dp);
        
        return dp[i][x] = max(last, start);
    }
    
    int maximumScore(vector<int>& n, vector<int>& m) {
        
        vector<vector<int>> dp(n.size(), vector<int>(m.size(), -1));
        return recurDP(n, m, 0, n.size()-1, 0, dp);
        
    }
};