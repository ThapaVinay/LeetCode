class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        unordered_set <int> st;
        
        for(auto n :nums)
        {
            st.insert(n);
        }
        
        int maxi = 1;
        for(auto n: st)
        {
            int curr = 1;
            
            if(st.find(n-1) == st.end())
            {
                while(st.find(++n) != st.end())
                {
                    curr ++;
                }
            }
            
            maxi = max(curr, maxi);
        }
        
        return maxi;
    }
};