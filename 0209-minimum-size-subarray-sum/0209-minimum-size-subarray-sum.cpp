class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = nums.size();
        int sum = 0;
        int min = INT_MAX;
        int j = 0;
        
        for(int i=0; i<l;)
        {
            sum += nums[i++];
            while(sum >= target)
            {
                min = std::min(min, (i-j));
                sum -= nums[j++];
            }
        }
        
        return min == INT_MAX ? 0 : min;
    }
};