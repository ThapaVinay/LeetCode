class Solution {
public:
    
    int satisfyDP(vector <int> &s, int index, int value, vector <vector<int>> &dp)
    {
        if(index >= s.size())
        {
            return 0;
        }
        
        if(dp[index][value] != -1)
        {
            return dp[index][value];
        }
        
        
        // taking dish
        int a = value * s[index] + satisfyDP(s, index+1, value+1, dp);
        
        // not take
        int b = satisfyDP(s, index+1, value, dp);
        
        dp[index][value] = max(a,b);
        return dp[index][value];
    }
    
    int maxSatisfaction(vector<int>& s) {
        
        vector <vector<int>> dp(s.size(), vector<int> (s.size()+1, -1));
        
        sort(s.begin(), s.end());
        return satisfyDP(s, 0, 1, dp);
    }
};