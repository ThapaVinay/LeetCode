class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1)
            return nums[0];
        
        sort(begin(nums), end(nums));
        
        int count = 1;
        int majority = nums.size()/2;
        int prev = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(prev == nums[i])
            {
                count ++;
            }
            else{
                prev = nums[i];
                count = 1;
            }
            
            if(count > majority)
                return nums[i];
        }
        
        return count;
        
    }
};