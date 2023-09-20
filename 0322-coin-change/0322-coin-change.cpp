class Solution {
public:
        
    int coinDP(vector<int> &coins, int amount, int index, int check, vector <vector<int>> &dp)
    {
        if(index == coins.size() || amount < 0)
        {
            return check+1;
        }
        
        if(amount == 0)
        {
            return 0;
        }

        if(dp[index][amount] != -1)
        {
            return dp[index][amount];
        }
        
        // take
        int take = 1 + coinDP(coins, amount-coins[index], index, check, dp);

        // not take
        int not_take = coinDP(coins,amount, index+1, check, dp);
            
        dp[index][amount] = min(take, not_take);
        return min(take, not_take);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0)
            return 0;
        
        vector <vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        
        int res = coinDP(coins, amount,0, amount, dp);
        
        if(res > amount)
        {
            return -1;
        }

        return res;
            
    }
};