class Solution {
public:
    
    int check(vector<int> nums, int sum)
    {
        int res = 1; 
        int x = 0;
        for(int i=0; i<nums.size(); i++)
        {
            x += nums[i];
            if(x > sum)
            {
                x = nums[i];
                res++;
            }
        }
        
        return res;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int sum = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, nums[i]);
        }
        
        int start = maxi;
        int end = sum;
        
        int mini = INT_MAX;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            int count = check(nums, mid);
            
            if(count <= k)
            {
                mini = min(mini, mid);
                end = mid - 1;
            }
            else{
                start = mid+1;
            }
        }

        return mini;
    }
};