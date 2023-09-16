class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int index = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(maxi <= nums[i])
            {
                maxi = nums[i];
                index = i;
            }
        }
        
        int i = (index+1) % nums.size();
        for(; i != index; i= (i+1)%nums.size())
        { 
            if(nums[i] > nums[(i+1)%nums.size()])
            {
                return -1;
            }
        }
        
        return nums.size() - (index+1);
    }
};