class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        
        int maxi = 0;
        int curr_maxi = 0;
        int j = 0;
        
        for(int i=t.size()-1; i>=0; i--)
        {
            curr_maxi = max(p[j] + t[i], curr_maxi);
            if(i % 4 == 0)
            {
                maxi = max(maxi, curr_maxi);
                curr_maxi = 0;
                j++;
            }
        }
        
        return maxi;
        
    }
};