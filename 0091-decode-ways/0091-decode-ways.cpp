class Solution {
public:
    
    int recurDP(string s, int i, vector<int> & dp)
    {
        
        
        if(i == s.size())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        // memo
        if(dp[i] != -1)
            return dp[i];
        
        // take one number
        int one_number = recurDP(s, i+1, dp);
        
        // take two numbers {only when less than 27}
        int two_numbers = 0;
        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
        {
            two_numbers = recurDP(s, i+2, dp);
        }
        
        return dp[i] = (one_number + two_numbers);
    }
    
    int numDecodings(string s) {
        
        // just focus on the number of ways if we can split the string rather than finding the values
        
        // we can either take one number or two numbers at once
        
        vector<int> dp(s.size(), -1);
        return recurDP(s, 0, dp);
    }
};