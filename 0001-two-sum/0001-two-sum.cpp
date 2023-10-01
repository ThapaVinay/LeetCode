class Solution {
public:
    vector <int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        vector <int> res(2,-1);
        
        for(int i=0; i<nums.size(); i++)
        {
            
            int diff = target - nums[i];
            
            if(mp[diff])
            {
                res[0] = i;
                res[1] = mp[diff]-1;
                break;
            }
            mp[nums[i]] = i+1;

        }
        
        return res;
    }
};