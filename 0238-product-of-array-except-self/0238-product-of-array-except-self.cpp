class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int total = 1;
        int n = nums.size();
        vector <int> res(n, 0);
        int index = -1;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0)
                total *= nums[i];
            else
            {
                index = i;
                count ++;
            }
                
        }
        
        if(count > 1)
        {
            return res;
        }
        
        if(count != 0)
        {
            res[index] = total;
        }
        else{
            for(int i=0; i<nums.size(); i++){
                res[i] = total/nums[i];
            }
        }
        return res;
    }
};