class Solution {
public:
    int minSteps(string s, string t) {
        
        // store s characters in map
        // remove t characters from map
        // those left are to be changed
        
        
        unordered_map <char, int> mp;
        
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]] ++;
        }
        
        
        for(int i=0; i<t.size(); i++)
        {
            mp[t[i]] --;
        }
        
        int count = 0;
        for(auto pair: mp)
        {
            if(pair.second > 0)
            {
                count += pair.second;
            }
        }
        
        return count;
    }
};