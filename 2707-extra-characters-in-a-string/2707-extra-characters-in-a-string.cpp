class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        
        int n = s.size();
        vector <int> dp(n+1, n);
        dp[0] = 0;
        
        for(int i=0; i<n; i++)
        {
            for(auto d : dictionary)
            {
                if(s.substr(i,d.size()) == d)
                {
                    dp[i + d.size()] = min(dp[i + d.size()], dp[i]);
                }
            }
            dp[i+1] = min(dp[i+1], dp[i] + 1);
        }
        
        return dp[n];
    }
};