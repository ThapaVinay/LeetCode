class Solution {
public:
    
    int  uniqueDP(int m, int n, int i, int j, vector <vector<int>> & dp)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        else if(i > m-1 || j > n-1)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
            
        
        // right
        int right = uniqueDP(m, n, i, j+1, dp);
        
        // down
        int down = uniqueDP(m, n,  i+1, j, dp);
        
        dp[i][j] = right + down;
        
        return dp[i][j];

    }
    
    int uniquePaths(int m, int n) {
        
        vector <vector<int>> dp(m , vector<int> (n,-1));
        return uniqueDP(m, n, 0, 0, dp);

    }
};