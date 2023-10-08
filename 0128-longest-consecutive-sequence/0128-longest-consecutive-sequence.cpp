class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int longest = 1;
        unordered_set<int> st;
        for(auto x : nums){
            st.insert(x);
        }
        for(auto s : st){
            if(st.find(s-1) == st.end()){
                int count = 1;
                int x = s;
                while(st.find(x+1) != st.end()){
                    count++;
                    x = x+1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};