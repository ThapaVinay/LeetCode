class Solution {
public:

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        unordered_map <int, int> row;
        unordered_map <int, int> col;
        unordered_map <int, int> d1;
        unordered_map <int, int> d2;
        
        vector<int> res;
        
        for(int i=0; i<lamps.size() ; i++)
        {
            int x = lamps[i][0];
            int y = lamps[i][1];
            
            row[x] ++;
            col[y] ++;
            d1[x-y] ++;
            d2[x+y] ++;
        }
        
        int dirs[9][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,0}};
              
        for(int i=0; i<queries.size(); i++)
        {
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            
            if(row[x1] || col[y1] || d1[x1-y1] || d2[x1+y1])
            {
                res.push_back(1);
                for(auto j : dirs)
                {
                    int new_x = x1 + j[0];
                    int new_y = y1 + j[1];
                    
                    if(new_y < 0 || new_y < 0 || new_x > n || new_y > n)
                        continue;
                    
                    for(int k=0; k<lamps.size(); k++)
                    {
                        if(lamps[k][0] == new_x && lamps[k][1] == new_y)
                        {
                            
                            lamps.erase(lamps.begin() + k);
                            k--;
                            
                            row[new_x] --;
                            col[new_y] --;
                            d1[new_x - new_y] --;
                            d2[new_x + new_y] --;
                        }
                    }
                }
            }
            else{
                res.push_back(0);
            }
        }
        
        return res;
    }
};