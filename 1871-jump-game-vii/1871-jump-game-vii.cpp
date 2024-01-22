class Solution {
public:
    
    bool recurDP(string &s, int mini, int maxi, int i, vector <int> &dp)
    {
        if(i == s.size()-1)
        {
            return true;
        }
        
        if(i >= s.size())
            return false;
        
        cout << dp[i] << endl;
        
        if(dp[i] != -1)
            return dp[i];
        
        // options 
        int start = i + mini;
        int end = min(i+maxi, static_cast<int>(s.size()-1));
        
        bool flag = false;
        while(start <= end)
        {
            if(s[start] == '0')
            {
                flag = flag || recurDP(s, mini, maxi, start, dp);
            }
            
            start ++;
        }
        
        return dp[i] = flag == true ? 1 : 0;
        
    }
    
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
        
        // vector <int> dp(s.size()+1, -1);
        
        // return recurDP(s, minJump, maxJump, 0, dp);
        return recurTab(s, minJump, maxJump);
        
    }
};