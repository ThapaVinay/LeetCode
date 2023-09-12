class Solution {
public:
    int minDeletions(string s) {
        // first store the occurances in a map
        // then make another map and compare them
        
        unordered_map <char, int> mp1;
        vector <int> check;
        
        for(auto ch: s)
        {
            mp1[ch] ++;
        }
        
        int count = 0;
        for(auto pair : mp1)
        {
            int a = pair.second;
            while(find(check.begin(), check.end(), a) != check.end())
            {
                a--;
                count ++;
            }
            if(a != 0)
                check.push_back(a);
        }
        
        return count;
    }
};