class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int count = 0;
        
        unordered_map <int, int> map;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= k)
                continue;
            
            int value = k - nums[i];
            if(map.find(nums[i]) != map.end() && map[nums[i]] != 0)
            {
                count ++;
                map[nums[i]]--;
                
            }
            else
                map[value] ++;
        }
        
        return count;
    }
};