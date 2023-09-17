class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        if(graph.size() == 1)
        {
            return 0;
        }
        
        int finalState = (1 << graph.size()) - 1;
        
        queue < pair<int,int>> q;
        vector <vector<int>> visited(graph.size(), vector<int>(finalState + 1, 0));
        
        // add all the values first because we can start from any node
        for(int i=0; i<graph.size(); i++)
        {
            q.push({i, 1 << i});
        }
        
        int shortest = 0;
        while(!q.empty())
        {
            int size = q.size();
            shortest ++;
            for(int i=0; i<size; i++)
            {
                auto val = q.front();
                q.pop();
                int node = val.first;
                int bitState = val.second;
                
                for(auto nb : graph[node])
                {
                    int newBitState = bitState | (1 << nb);
                    
                    if(visited[nb][newBitState])
                    {
                        continue;
                    }
                    
                    visited[nb][newBitState] = 1;
                    
                    if(newBitState == finalState)
                    {
                        return shortest;
                    }
                    
                    q.push({nb, newBitState});
                }
            }
        }
        return -1;

    }
};