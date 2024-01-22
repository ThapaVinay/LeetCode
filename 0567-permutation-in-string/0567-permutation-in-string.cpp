class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // just store all the characters of the string s1 in map and 
        // then check for them in s2
        
        if(s2.length() < s1.length())
            return false;
        
        unordered_map <char, int> mp, temp;
        
        for(auto ch: s1)
        {
            mp[ch] ++;
        }
        
        
        int words = s1.length();
        
        for(int i=0; i <= s2.length() - words; i++)
        {
            
            for(auto pair: mp)
            {
                temp[pair.first] = pair.second;
            }
            
            int count = 0;
            for(int j=i; j<s2.length(); j++)
            {
                char ch = s2[j];
                
                if(temp[ch])
                {
                    count ++;
                    temp[ch] --;
                }
                else{
                    break;
                }
            }
            
            if(count == words)
            {
                return true;
            }
        }
        
        return false;
    }
};