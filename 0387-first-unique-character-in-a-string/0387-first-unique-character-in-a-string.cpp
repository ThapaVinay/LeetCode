class Solution {
public:
    int firstUniqChar(string s) {
        
        int n = s.size();
        int arr[26] = {0};
        
        for(auto ch: s)
        {
            arr[ch - 'a'] ++;
        }
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(arr[ch-'a'] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};