class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        // djiktra algorithm...

        int r = heights.size();
        int c = heights[0].size();
        
        priority_queue <pair<int, pair<int,int>>, vector <pair<int, pair<int,int>>>, greater <pair<int, pair<int,int>>>> q;
        
        vector<vector<int>> dist(r, vector<int>(c,INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0,0}});
        
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            if(x == r-1 && y == c-1)
            {
                return diff;
            }
            
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if (new_x < 0 || new_x >= r|| new_y < 0 || new_y >= c) 
                    continue;
                
                int effort = max(abs(heights[x][y] - heights[new_x][new_y]), diff);
                
                if(effort < dist[new_x][new_y])
                {
                    dist[new_x][new_y] = effort;
                    q.push({effort, {new_x, new_y}});
                }
            }
        }
        
        return 0;
    }
};
