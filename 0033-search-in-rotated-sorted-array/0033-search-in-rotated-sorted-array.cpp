class Solution {
public:
    
    int find_peak(vector <int> &nums)
    {
        int start = 0, end = nums.size()-1;
        
        while(start < end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[start] < nums[mid])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }
    
    int binary_search(vector <int> &nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        // first find the maximum peak element
        // then break the array in two parts and use binary search on both of them
        
        int peak = find_peak(nums);
        
        cout << peak << endl;
        
        int a = binary_search(nums, 0, peak, target);
        int b = binary_search(nums, peak+1, nums.size()-1, target);
        
        if(a != -1)
            return a;
        
        if(b != -1)
            return b;
        
        return -1;
    }
};