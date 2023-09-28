class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        
        reverse(nums.begin(), nums.end()-k); // 0 -> n-k
        reverse(nums.begin() + (n-k), nums.end());  // n-k -> n
        reverse(nums.begin(), nums.end()); // 0 -> n
        
    }
};