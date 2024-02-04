class Solution {
public:
    
    unordered_map <string, int> mp;
    
    bool recurDP(string s1, string s2)
    {
        if(s1 == s2)
            return true;
        
        if(s1.size() != s2.size())
            return false;
        
        // memoization
        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end())
        {
            return mp[key];
        }
        
        int n = s1.size();
        int result = false;
        
        // checking all the points to split the string
        for(int i=1; i<n; i++)
        {
            
            //when we are swapping, then first substring of s1 will get compared with the second substring of s2.
            bool swapped = recurDP(s1.substr(i, n-i), s2.substr(0, n-i)) && recurDP(s1.substr(0, i), s2.substr(n-i, i));
            
            if(swapped)
            {
                result = true;
                break;
            }
            
            // not swapped, then same substring of s1 and s2 will be compared
            bool not_swapped = recurDP(s1.substr(i, n-i), s2.substr(i, n-i)) && recurDP(s1.substr(0, i), s2.substr(0, i));
            
            if(not_swapped)
            {
                result = true;
                break;
            }
        }
        
        return mp[key] = result;
        
    }
    
    bool isScramble(string s1, string s2) {
        
        mp.clear();
        return recurDP(s1, s2);
    }
};