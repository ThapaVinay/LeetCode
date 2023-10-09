class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() -1;
        vector <int> res;
        
        // to find the starting number
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {

                if(mid == 0)
                {
                    res.push_back(mid);
                    break;
                }
                else if(nums[mid-1] != target)
                {
                    res.push_back(mid);
                    break;
                }
                else{
                    r = mid - 1;
                }
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        l = 0, r= nums.size()-1;
        // to find the ending number
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                if(mid == nums.size()-1)
                {
                    res.push_back(mid);
                    break;
                }
                else if(nums[mid+1] != target)
                {
                    res.push_back(mid);
                    break;
                }
                else{
                    l = mid + 1;
                }
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        
        
        if(res.size() == 0)
            return {-1,-1};
 
        return res;
    }
};