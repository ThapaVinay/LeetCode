class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        if(words.size() == 1)
            return true;
        
        unordered_map <char, int> mp;
        for(int i=0; i<words.size(); i++)
        {
            for(auto ch: words[i])
            {
                mp[ch] ++;
            }
        }
        
        int size = words.size();
        for(auto pair: mp)
        {
            if(pair.second % size != 0)
                return false;
        }
        
        return true;
    }
};