class Solution {
public:
    int recurDP(vector<vector<int>>& grid, int i, int j, int r, int c, vector<vector<int>>& dp)
    {
        if(i == r-1 && j == c-1)
            return grid[i][j];
        
        if(i >= r || i < 0 || j >=c || j < 0)
            return 40000;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // go down
        int down = grid[i][j] + recurDP(grid, i+1, j, r, c, dp);
        
        // go right
        int right = grid[i][j] + recurDP(grid, i, j+1, r, c, dp);
        
        return dp[i][j] = min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector <vector<int>> dp(r, vector<int>(c, -1));
            
        return recurDP(grid, 0, 0, r, c, dp);
    }
};