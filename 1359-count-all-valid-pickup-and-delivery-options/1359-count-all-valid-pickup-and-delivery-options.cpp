class Solution {
public:
    int mod = 1e9 + 7;
    
    long countDP(int pick, int deliver, vector< vector<long>> &dp)
    {
        // base cases
        if(pick == 0 && deliver == 0)
        {
            return 1;
        }
        else if( pick < 0 || deliver < 0 || pick > deliver)
        {
            return 0;
        }
        
        if(dp[pick][deliver] != -1)
        {
            return dp[pick][deliver];
        }
        
        // two option pickup or deliver
        long res = (deliver - pick) * countDP(pick, deliver - 1, dp) + pick * countDP(pick-1, deliver, dp);
        
        dp[pick][deliver] = res % mod;  
        return dp[pick][deliver];

        
    }
    
    int countOrders(int n) {
        // there will be two options where to pickup or deliver
        // 1. only deliver when pickup is already done i.e. pickup < delivery
        // 2. only pickup when pickup is possible
        
        vector< vector<long>> dp(n+1, vector<long> (n+1, -1));
        
        return countDP(n,n, dp);
    }
};
