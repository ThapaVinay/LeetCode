class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            // at correct index
            if(nums[i] == i+1)
                continue;
            
            // negative and > size
            if(nums[i] <= 0 || nums[i] > n)
                continue;
            
            int x = nums[i]- 1;
            
            if(nums[x] == nums[i])
                continue;
            
            int temp = nums[x];
            nums[x] = nums[i];
            nums[i] = temp;
            i--;
            
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        
        return n+1;
        
    }
};