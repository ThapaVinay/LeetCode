class Solution {
public:
    int minimumPushes(string word) {
        
        // store the counts in array and sort and then add in keypad
        
        vector <int> arr(26, 0);
        for(auto ch: word)
        {
            arr[ch-'a'] ++;
        }
        
        sort(arr.begin(), arr.end(), greater<int>());
        
        int count = 1;
        int val = 1;
        int res = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
                break;
            
            res = res + (arr[i] * val);
            if(count == 8)
            {
                count = 1;
                val ++;
            }
            else
                count ++;
        }
        return res;
    }
};