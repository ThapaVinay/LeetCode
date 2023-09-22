class Solution {
public:
    
    void prevElement(vector <int> &h, vector <int> &prev)
    {
        stack <int> s;
        s.push(-1);
        for(int i=0; i<h.size(); i++)
        {
            
            while(s.top() != -1 && s.top() < h[i] )
            {
                s.pop();
            }
            
            prev[i] = s.top();
            if(s.top() < h[i])
                s.push(h[i]);
        }
    }
    
    void nextElement(vector <int> &h, vector <int> &next)
    {
        stack <int> s;
        s.push(-1);
        for(int i=h.size()-1; i>=0; i--)
        {
            while(s.top() != -1 && s.top() < h[i] )
            {
                s.pop();
            }
            
            next[i] = s.top();
            if(s.top() < h[i])
                s.push(h[i]);
        }
    }
    
    int trap(vector<int>& h) {
        
        int n = h.size();
        
        // find prev greatest element
        vector <int> prev(n , 0);
        prevElement(h, prev);
        
        // find next greatest element
        vector <int> next(n , 0);
        nextElement(h, next);
    
        int total = 0;
        for(int i=0; i<n; i++)
        {
            int mini = min(prev[i], next[i]);
            
            if(mini != -1)
                total += mini - h[i];
        }
        
        return total;
    }
};