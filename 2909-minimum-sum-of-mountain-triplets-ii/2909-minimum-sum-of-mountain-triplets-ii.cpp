class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <int> leftMin(n);
        vector <int> rightMin(n);
        
        int mini = INT_MAX;
        for(int i=0; i<n; i++)
        {
            leftMin[i] = mini;
            mini = min(mini, nums[i]);
        }
        
        mini = INT_MAX;
        for(int i=n-1; i>=0; i--)
        {
            rightMin[i] = mini;
            mini = min(mini, nums[i]);
        }
                
        mini = INT_MAX;
        for(int i=1; i<n-1; i++)
        {
            if(leftMin[i] < nums[i] && rightMin[i] < nums[i])
            {
                mini = min(mini, leftMin[i] + nums[i] + rightMin[i]);
            }
        }
        
        return mini == INT_MAX ? -1 : mini;
        
    }
};