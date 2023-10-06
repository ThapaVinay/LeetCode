class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map <int, int> mp;
        int sum = 0;
        
        mp[sum] ++;
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            
            if(rem < 0)
                rem += k;
            
            if(mp[rem])
                ans += mp[rem];
            
            mp[rem] ++;
        }
        
        return ans;
        
    }
};