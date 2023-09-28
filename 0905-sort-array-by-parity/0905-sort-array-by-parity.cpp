class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int l =0, r = nums.size()-1;
        
        while(l<r)
        {
            if(nums[l] % 2 == 0 && nums[r] % 2 != 0)
            {
                l++;
                r--;
            }
            
            else if(nums[r] % 2 != 0)
                r--;
            
            else if(nums[l] % 2 == 0)
                l++;
            
            else {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
        }
        
        return nums;
    }
};