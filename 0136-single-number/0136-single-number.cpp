class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int count = 1;
        
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            if(curr == nums[i])
            {
                count ++;
            }   
            else{
                if(count == 1)
                {
                    return curr;
                }
                count = 1;
                curr = nums[i];
            }
        }
        
        if(count == 1)
            return nums[nums.size()-1];
        
        return -1;
    }
};