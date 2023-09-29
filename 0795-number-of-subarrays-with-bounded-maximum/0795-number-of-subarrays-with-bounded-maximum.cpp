class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int ans = 0;
        int j = 0;
        int prevCount = 0;
        
        for(int i=0; i<nums.size(); i++)
        {   
            if(nums[i] >= left && nums[i] <= right)
            {
                ans += i-j+1;
                prevCount = i-j+1;
            }
            else if(nums[i] < left)
            {
                ans += prevCount;
            }
            else 
            {
                prevCount = 0;
                j = i+1;
            }            
        }
        return ans;
    }
};