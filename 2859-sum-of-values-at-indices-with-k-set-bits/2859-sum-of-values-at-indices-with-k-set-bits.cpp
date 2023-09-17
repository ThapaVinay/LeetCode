class Solution {
public:
    int sumRec(int n, vector <int> &arr)
    {
        if(n == 0)
            return 0;
        
        if(arr[n] != -1)
            return arr[n];
        
        int sum = 0;
        if(n % 2 == 1)
        {
            sum +=  1 + sumRec(n/2, arr);
        }
        else{
            sum += sumRec(n/2, arr);
        }
        
        arr[n] = sum;
        return sum;
    }
    
    
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int n = nums.size()-1;
        
        vector <int> arr(n+1, -1);
        int total = 0;
        
        for(int i=0; i<n+1; i++)
        {
            
            if(arr[i] == -1)
            {
                int count = sumRec(i, arr);
                if(count == k)
                {
                    total += nums[i];
                }
            }
            else if(arr[i] == k){
                total += nums[i];
            }
        }
        
        return total;
        
    }
};
