class Solution {
public:
    int wordCount(vector<string>& a, vector<string>& b) {
        
        // sort both the vectors and then check
        unordered_map <string, int> mp;
        for(auto &s: a)
        {
            sort(s.begin(), s.end());
            mp[s] ++;
        }
        
        for(auto &s: b)
        {
            sort(s.begin(), s.end());
        }
        
        int count = 0;
        for(auto &s : b)
        {
            for(int i=0; i<s.size(); i++)
            {
                string temp = "";
                for(int j=0; j<s.size(); j++)
                {
                    if(i == j)
                        continue;
                    
                    temp += s[j];
                }
                
                if(mp[temp])
                {
                    count ++;
                    break;
                }
            }
        }
        
        return count;
    }
};