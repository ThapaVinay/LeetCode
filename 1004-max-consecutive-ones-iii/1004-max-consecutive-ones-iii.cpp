class Solution {
public:
   int longestOnes(vector<int>& nums, int k) {
       
        if(k == 0)
        {
            int count = 0;
            int maxi = 0;
            for(auto i:nums)
            {
                if( i == 0)
                    count = 0;
                else{
                    count ++;
                }
                
                maxi = max(maxi, count);
            }
            return maxi;
        }
       
       int r = 0, l = 0;
       int count = 0;
       while(count < k && r<nums.size())
       {
           if(nums[r] == 0)
               count ++;
           r++;
       }
       int maxi = r;
       
       while(r < nums.size() && l<r)
       {
           if(count >= k && nums[r] == 0)
           {
               while(nums[l] != 0 && l<nums.size())
                   l++;
               l++;
               count --;
           }
           else if(nums[r] == 0){
               r++;
               count ++;
           }
           else{
               r++;
           }
           
           maxi = max(maxi, r-l);
       }
       
       return maxi;
    
    }

};
