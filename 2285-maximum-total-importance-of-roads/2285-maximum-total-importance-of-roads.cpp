class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        // assign the node with maximum edges with the maximum value
        
        unordered_map <int, vector<int>> mp;
        
        for(int i=0; i<roads.size(); i++)
        {
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<int> arr;
        for(auto pair: mp)
        {
            arr.push_back(pair.second.size());
        }
        
        sort(arr.begin(), arr.end());
        long long res = 0;
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            res += 1LL * n * arr[i];
            n--;
        }
        
        return res;
    }
};