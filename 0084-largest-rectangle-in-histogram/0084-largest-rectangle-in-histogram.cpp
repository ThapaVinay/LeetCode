class Solution {
public:
    
    // find next smallest (monotonicly increasing stack)
    void find_next_smaller(vector<int> &h, vector<int> &a, int n)
    {
        stack <int> st;
        st.push(-1);
        
        for(int i=n-1; i>=0; i--)
        {
            int val = h[i];
            
            while(st.top() != -1 && h[st.top()] >= val)
            {
                st.pop();
            }
            
            a[i] = st.top();
            st.push(i);
            
        }
        
    }
    
    // find prev smallest
    void find_prev_smaller(vector<int> &h, vector<int> &a, int n)
    {
        stack <int> st;
        st.push(-1);
        
        for(int i=0; i<n; i++)
        {
            int val = h[i];
            
            while(st.top() != -1 && h[st.top()] >= val)
            {
                st.pop();
            }
            
            a[i] = st.top();
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& h) {
        
        int n = h.size();
        vector <int> next_smaller(n);
        vector <int> prev_smaller(n);
        
        find_next_smaller(h, next_smaller, n);
        find_prev_smaller(h, prev_smaller, n);
        
        
        for(auto i: next_smaller)
        {
            cout << i << " ";
        }
        
        // find area
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(next_smaller[i] == -1)
            {
                next_smaller[i] = n;
            }
            
            int area = (next_smaller[i] - prev_smaller[i] - 1) * h[i];
            maxi = max(maxi, area);
        }
        
        return maxi;
        
        
        
    }
};