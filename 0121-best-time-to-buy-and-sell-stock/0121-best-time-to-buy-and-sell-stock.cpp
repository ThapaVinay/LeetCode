class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        // find the greatest element after that index
        vector <int> greatest(n);
        
        int maxi = prices[n-1];
        greatest[n-1] = -1;
        
        for(int i= n-2; i>=0; i--)
        {
            maxi = max(prices[i], maxi);
            greatest[i] = maxi;
        }
        
        int profit = 0;
        for(int i=0; i<n-1; i++)
        {
            profit = max(profit, greatest[i] - prices[i]);
        }
        
        return profit;
    }
};