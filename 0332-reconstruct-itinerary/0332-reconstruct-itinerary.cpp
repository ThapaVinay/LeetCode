class Solution {
public:
    bool found = false;
    void dfs(unordered_map<string, vector<string>> &mp, string check,int s, vector <string> &res)
    {
        if(found)
            return;
        
        if(res.size() == s)
        {
            found = true;
            return;
        }
        
        if(mp[check].size() == 0)
        {
            return;
        }
        
        for(int x = mp[check].size()-1; x >=0 ;x--)
        {
            res.push_back(mp[check][x]);
            string temp = mp[check][x];
            mp[check].erase(mp[check].begin() + x);
            dfs(mp, temp, s, res);
            if(found)
                break;
            
            mp[check].insert(mp[check].begin() + x, temp);
            res.pop_back();
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map <string, vector<string>> mp;
        vector <string> res;
        
        for(auto vec : tickets)
        {
            mp[vec[0]].push_back(vec[1]);
        }
        
        for(auto &pair : mp)
        {
            sort(pair.second.begin(), pair.second.end(), greater<string>());
        }

        res.push_back("JFK");
        dfs(mp, "JFK", tickets.size() + 1, res);
        return res;
    }
};
