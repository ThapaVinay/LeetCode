class Solution {
public:

    bool recurTab(string s, int mini, int maxi)
    {
        vector <bool> dp(s.size()+1, false);
        
        dp[0] = true;
        
        int n = s.size();
        int x = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(!dp[i])
                continue;
            
            int start = max(x, i + mini);
            int end = min(i + maxi, n-1);
            
            while(start <= end)
            {
                if(s[start] == '0')
                {
                    dp[start] = true;
                }
                start ++;
            }
            x = end + 1;
        }
        
        return dp[n-1];
        
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        
        // at each index we will have option between i+minJump to i+maxJump
        
        return recurTab(s, minJump, maxJump);
        
    }
};