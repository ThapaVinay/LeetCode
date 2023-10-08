class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        unordered_set <int> st;
        
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        
        int maxi = 1;
        for(int i=0; i<nums.size(); i++)
        {
            int curr = 1;
            int n = nums[i];
            
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