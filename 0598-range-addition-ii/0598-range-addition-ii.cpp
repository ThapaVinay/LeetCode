class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        
        if(ops.size() == 0)
            return m*n;
        
        for(int i=0; i<ops.size(); i++)
        {
            min_x = min(min_x, ops[i][0]);
            min_y = min(min_y, ops[i][1]);
        }
        
        int count = min_x * min_y;
        
        return count;
        
    }
};