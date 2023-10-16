class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.size() > s.size())
        {
            return {};
        }
        
        unordered_map <char, int> mp1;
        for(int i=0; i<p.size(); i++)
        {
            mp1[p[i]]++;
        }
        
        unordered_map <char, int> mp2;
        vector <int> res;
            
        int l = 0;
        for(int r=0; r<=s.size(); )
        {
            bool flag = true;
            if(r-l >= p.size())
            {
                for(auto pair: mp1)
                {
                    if(mp2[pair.first] != pair.second)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    res.push_back(l);
                }
                mp2[s[l]]--;
                l++;
                
            }
            else{
                mp2[s[r]] ++;
                r++;
            }
            
        }
        
        
        return res;
    }
};