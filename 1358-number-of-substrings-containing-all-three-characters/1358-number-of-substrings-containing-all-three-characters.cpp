class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int l=0;
        unordered_map <char, int> mp;
        int count = 0;
        int n = s.size();
        
        for(int r =0; r<n ;r++)
        {
            mp[s[r] - 'a']++;
            while(mp[0] && mp[1] && mp[2] && l<=r)
            {
                count += n-r;
                mp[s[l]-'a'] --;
                l++;
            }  
        }
        
        return count;
    }
};