class Solution {
public:
    
    int paintRec(vector<int>& cost, vector<int>& time, int remain, int i, vector <vector <int>> &dp)
    {
        if(remain <= 0)
        {
            return 0;
        }
        
        if(i >= cost.size())
        {
            return 1e9;
        }
        
        if(dp[remain][i] != -1)
        {
            return dp[remain][i];
        }
        
        // take
        int take = cost[i] + paintRec(cost, time, remain - time[i] -1 , i+1, dp);
        
        // not_take
        int not_take = paintRec(cost, time, remain, i+1, dp);
        
        return dp[remain][i] = min(take, not_take);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        vector <vector <int>> dp(cost.size()+1, vector<int>(cost.size()+1, -1));
        
        return paintRec(cost, time, cost.size(), 0, dp);

        
    }
};