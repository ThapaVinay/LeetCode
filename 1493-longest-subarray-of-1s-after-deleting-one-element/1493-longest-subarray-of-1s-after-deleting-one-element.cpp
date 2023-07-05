class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = 0;
        int curr = 0;
        int prev = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                if(curr+prev > max)
                {
                    max = curr+prev;
                }
                prev = curr;
                curr = 0;
            }
            else{
                curr ++;
            }
        }
        
        if(prev == -1)
        {
            return curr - 1;
        }
        
        if(curr+prev > max)
        {
            max= curr + prev;
        }
        
        return max;
    }
};