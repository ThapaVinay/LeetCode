class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
    
          static int N = [] () {
            ios::sync_with_stdio(false); 
            cin.tie(0); 
            return 0;
        } ();
        int s = nums.size();
        int Sum = 0;
        int res = INT_MAX;
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        for (int l = 0, r = 0, Sum = 0; r < s; r++) {
            Sum += nums[r];
            while ( Sum > target && l <= r) {
                Sum -= nums[l];
                l++;
            }
            if (Sum == target)
                res = std::min(res, s-(r-l+1));
        }
        return res == INT_MAX ? -1 : res;
        
    }
};