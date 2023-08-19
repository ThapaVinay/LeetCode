class Solution {
public:
    
    int Tab(vector <int> &s)
    {
        int n = s.size();
        vector <vector<int>> dp(n+1, vector<int> (n+2, 0));
        
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=n; j>=1; j--)
            {
                int a = j * s[i] + dp[i+1][j+1];
                int b = dp[i+1][j];
                dp[i][j] = max(a,b);
            }
        }
        return dp[0][1];
    }
    
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
        
        // vector <vector<int>> dp(s.size(), vector<int> (s.size()+1, -1));
        
        sort(s.begin(), s.end());
        // return satisfyDP(s, 0, 1, dp);
        
        return Tab(s);
    }
};