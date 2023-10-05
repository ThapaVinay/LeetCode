class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map <int, int> mp;
        int maxi = -1;
        
        for(auto arr: wall)
        {
            int count = 0;
            for(int i=0; i<arr.size()-1; i++)
            {
                count += arr[i];
                mp[count] ++;
                
                maxi = max(maxi, mp[count]);
            }
        }
        
        if(maxi == -1)
            return wall.size();
        
        return wall.size() - maxi;
        
    }
};