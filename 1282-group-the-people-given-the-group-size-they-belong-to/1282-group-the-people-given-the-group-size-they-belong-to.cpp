class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        
        // make a map with vector as value and int as key
        // then just enter the values and when value's size is equal to the key then append it to res
        
        unordered_map <int, vector<int>> mp;
        vector <vector <int>> res;
        
        for(int i=0; i<g.size(); i++)
        {
            mp[g[i]].push_back(i);
            
            if(mp[g[i]].size() == g[i])
            {
                res.push_back(mp[g[i]]);
                mp[g[i]].clear();
            }
        }
        
        return res;
    }
};