class Solution {
public:
    
    int no;
    int checkRec(int n, vector <int> &dp)
    {
        if(n == 1 || n < 0)
        {
            return no;
        }
        
        if(n == 0)
        {
            return 0;
        }
            
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int three = 1 + checkRec(n-3, dp);
        
        int two = 1 + checkRec(n-2, dp); 
        
        dp[n] = min(three,two);
        return dp[n];
    }
    
    int minOperations(vector<int>& nums) {
        
        unordered_map <int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        int total_count = 0;
         
        for(auto pair: mp)
        {
            
            if(pair.second == 1)
                return -1;
            
            no = pair.second;
            
            vector <int> dp(no+1, -1);
            int count = checkRec(pair.second, dp);
            
            if( count < no)
                total_count += count;
            else
                return -1;
            
           
        }
        
        return total_count;
    }
};