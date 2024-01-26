class Solution {
public:
    
    int MOD = 1e9 + 7;
    
    int dp[51][51][51];
    
    int recurDP(int m, int n, int maxMove, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        // left
        long left = recurDP(m, n, maxMove-1, i-1, j);
        
        // right
        long right = recurDP(m, n, maxMove-1, i+1, j);
        
        // top
        long top = recurDP(m, n, maxMove-1, i, j-1);
        
        // bottom
        long bottom = recurDP(m, n, maxMove-1, i, j+1);
        
        return dp[i][j][maxMove] = (left + right + top + bottom) % MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        // Initialize the array with -1
        for (int i = 0; i < 51; ++i) 
        {
            for (int j = 0; j < 51; ++j) 
            {
                for (int k = 0; k < 51; ++k) 
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return recurDP(m, n, maxMove, startRow, startColumn);
        
    }
};