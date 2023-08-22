class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector <pair<int,int>> row;
        vector <pair<int,int>> col;
        
        vector<vector<int>> res(grid.size(), vector<int>(grid.size(),0));
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                int maxr = 0;
                int maxc = 0;
                
                
                for(int k=0; k<grid.size(); k++)
                {
                    if(maxr < grid[i][k])
                    {
                        maxr= grid[i][k];
                    }
                    
                    if(maxc < grid[k][j])
                    {
                        maxc = grid[k][j];
                    } 
                }
                row.push_back(make_pair(i,maxr));
                col.push_back(make_pair(j,maxc));
                
                res[i][j] = min(maxr, maxc);
                
            }
        } 
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                ans =  ans + (res[i][j] - grid[i][j]);
            }
        }
        
        return ans;
    }
};