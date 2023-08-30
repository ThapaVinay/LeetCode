class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long res = 0;
        int n = nums.size();
        int prev = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] > prev)
            {

                int a = nums[i]/prev;
                
                if(nums[i] % prev != 0)
                {
                    a++;
                }
                
                prev = nums[i]/a;
                res += a-1;
            }
            else{
                prev = nums[i];
            }

        }
        
        return res;
    }
};