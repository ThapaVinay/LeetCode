class Solution {
public:
    
    int uniqueDP(vector<vector<int>> &obstacle, int x, int y, int m, int n, vector<vector<int>> &dp)
    {
        if( x >= m || y >= n || obstacle[x][y] == 1)
        {
            return 0;
        }
        
         if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        
        if(x == m-1 && y == n-1)
        {
            return 1;
        }
        
       
        
        dp[x][y] = uniqueDP(obstacle, x, y+1, m,n, dp) + uniqueDP(obstacle,  x+1, y, m,n, dp);
        return dp[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return uniqueDP(obstacleGrid, 0, 0, m, n, dp);
    }
};