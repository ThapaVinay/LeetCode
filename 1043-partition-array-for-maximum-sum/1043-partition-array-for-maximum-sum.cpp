class Solution {
public:
    
    int recurDP(vector <int> &arr, int k, int start,  vector<int>& dp)
    {
        if(start >= arr.size())
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        int res = 0;
        int maxi = -1;
        
        // maximum size of the subarray
        int end = min(start+k-1, static_cast<int>(arr.size()-1));
        
        for(int i=start; i<=end; i++)
        {
            maxi = max(maxi, arr[i]);
            res = max(res, (i-start+1)*maxi + recurDP(arr, k, i+1, dp));
        }
        
        return dp[start] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        // we will have options to select from start to start + k
        
        vector<int> dp(arr.size(), -1);
        return recurDP(arr,k , 0, dp);
    }
};