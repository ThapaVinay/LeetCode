class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        
        // use the concept of kadane 
        int count = 0;
        for(int i=0; i<n; i++)
        {
            unordered_map <int, int> mp;
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                
                int x1 = points[i][0] - points[j][0];
                int y1 = points[i][1] - points[j][1];
                
                int val = pow(x1,2) + pow(y1, 2);
                
                if(mp[val])
                {
                    count += mp[val];
                }
                mp[val] += 2;
            }
        }
        
        return count;
    }
};