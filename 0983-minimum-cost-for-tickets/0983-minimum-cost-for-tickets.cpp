class Solution {
public:
    
    int costDP(vector <int> &days, vector <int> &costs, int index, vector <int>& dp)
    {
        if(index >= days.size())
        {
            return 0;
        }
        
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        // 1 day
        int a = costs[0] + costDP(days, costs, index+1, dp);
        
        // 7 day
        int i;
        for(i=index; i<days.size() && days[i] < days[index]+7; i++);
        int b = costs[1] + costDP(days, costs, i, dp);
        
        // 30 day
        for(i=index; i<days.size() && days[i] < days[index]+30; i++);
        int c = costs[2] + costDP(days, costs, i, dp);
        
        return dp[index] = min(a, min(b,c));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp(days.size(), -1);
        return costDP(days, costs, 0, dp);
        
    }
};