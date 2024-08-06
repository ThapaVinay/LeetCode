class Solution {
public:

    int minSwaps(vector<int>& nums) {
        
        // use sliding window 
        // first try to group 1's and then 0's

        int count = 0;
        for(auto &n: nums)
            count += (n == 1);
        
        // group 1's
        int i = 0, swaps = 0;
        while(i < count)
        {
            swaps += (nums[i] == 0);
            i++;
        }

        int mini1 = swaps;
        while(i < nums.size())
        {
            swaps -= (nums[i - count] == 0);
            swaps += (nums[i] == 0);
            mini1 = min(mini1, swaps);
            i++;
        }
        
        // group 0's
        i=0, swaps = 0;
        count = nums.size() - count;
        while(i < count)
        {
            swaps += (nums[i] == 1);
            i++;
        }

        int mini2 = swaps;
        while(i < nums.size())
        {
            swaps -= (nums[i - count] == 1);
            swaps += (nums[i] == 1);
            mini2 = min(mini2, swaps);
            i++;
        }

        return min(mini1, mini2);
    }
};