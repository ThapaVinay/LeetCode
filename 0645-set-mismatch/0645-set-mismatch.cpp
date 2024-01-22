class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map <int, int> mp;
        set <int> st;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            st.insert(i+1);
        }
        
        int rep, missing;
        
        for(auto pair: mp)
        {
            st.erase(st.find(pair.first));
            if(pair.second > 1)
                rep = pair.first;
        }
        
        missing = *st.begin();
        
        return {rep, missing};
    }
};