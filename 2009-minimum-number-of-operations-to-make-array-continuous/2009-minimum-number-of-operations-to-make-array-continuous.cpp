class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int mini = INT_MAX;
        
        // only take unique elements
        set <int> s(nums.begin(), nums.end());
        vector <int> st(s.begin(), s.end());
        
        for(int i=0; i<st.size(); i++)
        {
            int range = st[i] + n-1;
            
            int l = i;
            int r = st.size();
            
            // finding the upper bound
            while(l < r)
            {
                int mid = l + (r-l)/2;
                
                if(st[mid] <= range)
                {
                    l = mid+1;
                }  
                else{
                    r = mid;
                }
            }
            
            // finding the within range
            int within_range = l-i;
            int out_range = n-within_range;
            
            mini = min(mini, out_range);
        }

        return mini;
    }
};