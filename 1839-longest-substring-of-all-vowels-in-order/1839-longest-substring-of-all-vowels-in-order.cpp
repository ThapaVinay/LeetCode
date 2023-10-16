class Solution {
public:
    int longestBeautifulSubstring(string s) {
        
        int count = 1;
        int len = 1;
        int maxi = 0;
        
        for(int i=1; i<s.size(); i++)
        {
            if(s[i-1] == s[i])
            {
                len++;
            }
            else if(s[i-1] < s[i])
            {
                len ++;
                count ++;
            }
            else{
                len = 1;
                count = 1;
            }
            
            if(count == 5)
                maxi = max(maxi, len);
        }
        
        return maxi;
    }
};
