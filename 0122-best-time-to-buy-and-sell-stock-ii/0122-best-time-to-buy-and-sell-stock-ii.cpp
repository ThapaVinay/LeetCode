class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // just if prices[i+1] > prices[i], if so then add its difference to the result
        
        int ans = 0;
        for(int i=0; i<prices.size()-1; i++)
        {
            if(prices[i+1] > prices[i])
            {
                ans += prices[i+1] - prices[i];
            }
        }
        
        return ans;
    }
};


// 4 + 3 + 2 + 4 + 1