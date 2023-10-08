class Solution {
public:
    
    int m, n;
    
    int solveDP(vector<int>& nums1, vector<int>& nums2, int i, int j, vector <vector<int>> & dp)
    {
        
        if(i == m || j == n)
        {
            return -10000000;
        }
        
        if(dp[i][j] != -1e9)
        {
            return dp[i][j];
        }
        
        int val = nums1[i] * nums2[j];
        
        // take i & j
        int take_i_j = val + solveDP(nums1, nums2, i+1, j+1, dp);
        
        // take i and skip j
        int take_i = solveDP(nums1, nums2, i, j+1, dp);
        
        // take j and skip i
        int take_j = solveDP(nums1, nums2, i+1, j, dp);
        
        return dp[i][j] = max({val, take_i_j, take_i, take_j});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        m = nums1.size();
        n = nums2.size();
        
        vector <vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1e9));
        return solveDP(nums1, nums2, 0, 0, dp) ;
        
    }
};