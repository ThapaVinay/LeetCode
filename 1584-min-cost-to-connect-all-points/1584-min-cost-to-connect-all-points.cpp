class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        // define three vector for key, visited and parent
        vector <int> key(n, INT_MAX);
        vector <bool> mst(n, false);
        vector <int> parent(n, -1);
        
        // starting with node 0
        key[0] = 0;
        for(int i=0; i<n; i++)
        {
            // initialise the minimum and the current node
            int mini = INT_MAX;
            int u;
            
            // find minimum value
            for(int j=0; j<n; j++)
            {
                if(mst[j] == false && key[j] < mini)
                {
                    // change minimum and current node
                    mini = key[j];
                    u = j;
                }
            }
            
            // set the node to visited
            mst[u] = true;
            
            // check its adjacent nodes
            for(int k=0; k<n; k++)
            {
                int temp = abs(points[u][0] - points[k][0]) + abs(points[u][1] - points[k][1]);
                // change their values to the minimum
                if(mst[k] == false && temp < key[k])
                {
                    parent[k] = u;
                    key[k] = temp;
                }
            }
            
        }
        
                
        int cost = 0;
        for(int i=1; i<n; i++)
        {
            int j = parent[i];
            cost +=  abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        }

        return cost;
    }
};