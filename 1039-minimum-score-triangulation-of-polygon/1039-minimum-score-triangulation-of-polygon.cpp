class Solution {
public:
    
    int minDP(vector<int> &values,int i, int j, vector <vector<int>> & dp)
    {
        if(i+1 == j)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for(int k = i+1; k<j ;k++)
        {
            ans = min(ans, (values[k]*values[i]*values[j]) + minDP(values,i,k,dp) + minDP(values,k,j, dp));
        }
        dp[i][j] = ans;
        return ans;
        
    }
    
    int minScoreTriangulation(vector<int>& values){
        
        vector <vector<int>> dp(values.size(),vector<int> (values.size(),-1));
        int total = values.size() -2;
        return minDP(values, 0, values.size()-1, dp);
    }
};