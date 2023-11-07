class Solution {
public:
 
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        // find the first index to swap
        int index = -1;
        
        for(int i = n-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                index = i-1;
                break;
            }
        }
        
        // it is the last permutation
        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find the second index to swap
        for(int i=n-1; i>index; i--)
        {
            if(nums[index] < nums[i])
            {
                swap(nums[index], nums[i]);
                break;
            }
        }
        
        // reverse the elements from first element onwards
        reverse(nums.begin() + index +1, nums.end());

    }
};