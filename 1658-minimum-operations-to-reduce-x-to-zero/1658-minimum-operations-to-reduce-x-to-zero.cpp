class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        
        int s = nums.size();
        int sum = 0;
        int res = INT_MAX;
        
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        for (int l = 0, r = 0, sum = 0; r < s; r++) 
        {
            sum += nums[r];
            while ( sum > target && l <= r) {
                sum -= nums[l];
                l++;
            }
            if (sum == target)
                res = min(res, s-(r-l+1));
        }
        
        return res == INT_MAX ? -1 : res;
        
    }
};