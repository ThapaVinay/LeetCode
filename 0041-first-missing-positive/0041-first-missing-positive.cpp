class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        map <int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                mp[nums[i]] ++;
            }
        }
        
        for(int i=1; i<2147483647; i++)
        {
            if(!mp[i])
                return i;
        }
        
        return -1;
    }
};