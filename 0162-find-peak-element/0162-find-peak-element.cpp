class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // binary search

        if(nums.size() == 1)
            return 0;

        int start = 0, end = nums.size();

        while(start <= end)
        {
            int mid = (start + end)/2;

            if(mid == 0 && nums[mid] > nums[mid+1])
            {
                return mid;
            }

            if(mid == nums.size() - 1 && nums[mid] > nums[mid-1])
            {
                return mid;
            }

            if(mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }

            if(mid > 0 && nums[mid] > nums[mid - 1])
            {
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }

        return -1;
    }
};