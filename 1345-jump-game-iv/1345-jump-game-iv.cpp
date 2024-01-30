class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        // first save the elements with their occurances in a map to make graph
        // then use bfs to iterate using queue
        // you will have three options : curr + 1, curr - 1 or next == curr
        
        unordered_map <int, vector<int>> mp;
        
        int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        // use bfs
        queue <int> q;
        q.push(0);
        int steps = 0;
        
        vector <int> visited(n, 0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                int front = q.front();
                q.pop();
                
                if(front == n-1)
                {
                    return steps;
                }
                
                int left = front - 1;
                int right = front + 1;
                
                if(right < n && !visited[right])
                {
                    q.push(right);
                    visited[right] = 1;
                }

                if(left >= 0 && !visited[left])
                {
                    q.push(left);
                    visited[left] = 1;
                }  
                
                for(auto & x: mp[arr[front]])
                {
                     if(!visited[x]) 
                     {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
                mp.erase(arr[front]);
            }  
            steps ++;
            
        }
        return steps;
    }
};