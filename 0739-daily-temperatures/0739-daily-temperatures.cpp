class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        // use monotonicly decreasing stack from end to find the next max
        
        stack <int> st;
        int n = t.size();
        st.push(-1);
        vector <int> arr(n);    
    
        for(int i=n-1; i>=0; i--)
        {
            while(st.top() != -1 && t[st.top()] <= t[i])
            {
                st.pop();
                               
            }
            
            if(st.top() == -1)
            {
                arr[i] = 0;
            }
            else{
                arr[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return arr;
        
    }
};