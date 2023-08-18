class Solution {
public:
    
    int maximalDP(vector<vector<char>>& matrix, int i, int j, int &ans, vector<vector<int>>& dp)
    {
        if( i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        // go right
        int r = maximalDP(matrix, i, j+1, ans, dp);
        
        // go diagnol 
        int l = maximalDP(matrix, i+1, j+1, ans, dp);
        
        // go bottom
        int b = maximalDP(matrix, i+1, j, ans, dp);
        
        
        if(matrix[i][j] == '1')
        {
            int temp = 1 + min(r, min(l,b));
            ans = max(ans,temp*temp);
            dp[i][j] = temp;
            return temp;
            
        }
        else{
            return 0;
        }
        
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        maximalDP(matrix, 0, 0, ans, dp);
        return ans;
    }
};