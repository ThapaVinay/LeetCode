class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return {nums[0]};
        }
        
        int a = nums[0], b = nums[1];
        int count1 = 0, count2 = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(a == nums[i])
                count1 ++;
            else if(b == nums[i])
                count2 ++;
            else if(count1 == 0)
            {
                count1 = 1;
                a = nums[i];
            }
            else if(count2 == 0)
            {
                count2 = 1;
                b = nums[i];
            }
            else{
                count1 --;
                count2 --;
            }
        }
        
        count1 = count2 = 0;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] == a)
                count1++;
            else if (nums[i] == b)
                count2++;
        }
        
        vector <int> res;
                
        if(count1 > floor(nums.size()/3))
        {
            res.push_back(a);
        }
        
        if(count2 > floor(nums.size()/3))
        {
            res.push_back(b);
        }
        
        
                
        return res;
    }
};