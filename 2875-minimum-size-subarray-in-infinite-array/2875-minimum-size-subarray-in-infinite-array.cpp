class Solution {
public:

    int minSizeSubarray(vector<int>& nums, int target) {
        
        long long total = 0;
        int n = nums.size();
        int extra  = 0;
        
        for(auto val: nums)
            total += val;
        
        if(target > total)
        {
            extra = (target/total)*n;
            target = target % total;
        }
        
        int l=0, r=0;
        long long curr = 0;
        int mini = INT_MAX;

        while(r <= 2*n)
        {
            curr += nums[r%n];
            
            while(curr > target)
            {
                curr -= nums[l%n];
                l++;
            }
            
            if(curr == target)
            {
                mini = min(mini, r-l+1);
            }
            r++;
        }
       
        if(mini == INT_MAX)
            return -1;
        else
            return mini + extra;

    }
};