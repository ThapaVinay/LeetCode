class Solution {
public:
    int maxVowels(string s, int k) {
        vector <char> check = {'a', 'e', 'i', 'o', 'u'};
        
        int count = 0;
        for(int i=0; i<k ; i++)
        {
            if(find(check.begin(), check.end(), s[i]) != check.end())
            {
                s[i] = '1';
                count ++;
            }
        }
        
        int max = count;
        int j = 0;
        for(int i=k; i<s.size(); i++, j++)
        {
            // cout << count << endl;
            if(s[j] == '1')
            {
                count --;
            }
            
            if(find(check.begin(), check.end(), s[i]) != check.end())
            {
                s[i] = '1';
                count ++;
            }
            
            if(max < count)
            {
                max = count;
            }
            
        }
        
        return max;
    }
};