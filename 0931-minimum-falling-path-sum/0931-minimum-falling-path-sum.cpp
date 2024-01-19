class Solution {
public:
    
    
    int recurDP(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp)
    {
        if(i == matrix.size())
        {
            return 0;
        }
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        int ans = matrix[i][j] + recurDP(matrix, i+1, j, dp);
        
        if(j-1 >= 0)
            ans = min(ans, matrix[i][j] + recurDP(matrix, i+1, j-1, dp));
        
        if(j+1 < matrix.size())
            ans = min(ans, matrix[i][j] + recurDP(matrix, i+1, j+1, dp));
        
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        vector<vector<int>> dp (matrix.size()+1, vector<int>(matrix.size()+1, INT_MAX));
        
        int ans = INT_MAX;
        for(int j=0; j<matrix.size(); j++)
            ans = min(ans,recurDP(matrix, 0, j, dp));
        
        return ans;
        
    }
};