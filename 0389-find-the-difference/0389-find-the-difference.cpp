class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int arr[26] = {0};
        
        for(auto &ch : t)
        {
            arr[ch - 'a'] ++;
        }
        
        for(auto &ch : s)
        {
            arr[ch - 'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(arr[i] != 0)
            {
                return (char)('a' + i);
            }
        }
        
        return '0';
        
    }
};