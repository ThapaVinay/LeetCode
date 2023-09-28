class Solution {
public:
    int nextGreaterElement(int n) {
        // check from last if we have a integer greater than that in the right side
        // if there is then just swap and sort the array after that index
        
        
        vector <int> nums;
        
        while(n != 0)
        {
            int rem = n%10;
            nums.push_back(rem);
            n = n/10;
        }
        
        int size = nums.size();
        reverse(begin(nums), end(nums));
        
        // find the greater element 
        int i, j=size-1;
        for(i=size-2; i>=0; i--)
        {
            if(nums[i] >= nums[j])
            {
                j--;
            }
            else{
                while(j < size && nums[i] < nums[j])
                {
                    j++;
                }
                j--;
                break;
            }
            
        }
        
        if( i < 0)
            return -1;
        
        // swap them
        swap(nums[i], nums[j]);
        
        // sort the array from i+1
        sort(nums.begin() + i+1, nums.end());
        
        long res = 0;
        for(i=0; i<size; i++)
        {
            res += nums[i];
            
            if(i < size-1)
                res *= 10;
            
        }
        
        if(res > INT_MAX)
            return -1;
        
        return res;
        
    }
};