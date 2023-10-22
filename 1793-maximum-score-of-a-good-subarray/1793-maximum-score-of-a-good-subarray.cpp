class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector <int> minArr(n);
        
        int mini = INT_MAX;
        for(int i=k; i<n; i++)
        {
            mini = min(mini, nums[i]);
            minArr[i] = mini;
        }
        
        mini = INT_MAX;
        for(int i=k; i>=0; i--)
        {
            mini = min(mini, nums[i]);
            minArr[i] = mini;
        }
        
        int res = 0;
        if(k == 0)
        {
            for(int i=0; i<n; i++)
            {
                res = max(res, minArr[i] * (i-k+1));
            }
        }
        else if(k == n-1)
        {
            for(int i=n-1; i>=0; i--)
            {
                res = max(res, minArr[i] * (k-i+1));
            }
        }
        else{
            int i=k-1, j = k+1;
            
            while(i >= 0 || j<=n-1)
            {
                if(i >= 0 && j <= n-1)
                {
                    if(minArr[i] > minArr[j])
                    {
                        res = max(res, minArr[i] * (j-i));
                        i--;
                    }
                    else{
                        res = max(res, minArr[j] * (j-i));
                        j++;
                    }
                    
                }
                else if(i >= 0)
                {
                    res = max(res, minArr[i] * (j-i));
                    i--;
                }
                else{
                    res = max(res, minArr[j] * (j-i));
                    j++;
                }
            }
        }
        
        
        return res;
    }
};