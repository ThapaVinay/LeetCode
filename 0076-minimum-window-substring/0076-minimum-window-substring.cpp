class Solution {
public:
    string minWindow(string s, string p) {
        
        int n = s.size();
        
        if(p.size() > n)
        {
            return "";
        }
        
        unordered_map <char, int> mp;
        
        for(auto ch: p)
        {
            mp[ch] ++;
        }
        
        int l =0, r= 0;
        int countRequired = p.size();
        
        int minWindow = INT_MAX;
        int start_i;
        
        while(r < n)
        {
            char ch = s[r];
            
            if(mp[ch] > 0)
            {
                countRequired --;
            }
            
            mp[ch] --;
            
            while(countRequired == 0)
            {
                int curr = r-l+1;
                
                if(minWindow > curr)
                {
                    minWindow = curr;
                    start_i = l;
                }
                
                mp[s[l]] ++;
                
                if(mp[s[l]] > 0)
                {
                    countRequired ++;
                }
                
                l++;
            }
            r++;
        }
        return minWindow == INT_MAX ? "" : s.substr(start_i, minWindow);
    }
};