class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        char ch = s[0];
        vector <int> res(26,-1);
        
        int max = 0;
        int flag = false;
        for(int i=0; i<s.size(); i++)
        {
            int index = (int)s[i] - 97;
            if(res[index] != -1)
            {
                int temp = (i - res[index])-1;
                if(max < temp)
                {
                    max = temp; 
                }
                flag = true;
            }
            else{
                res[index] = i;
            }
        }
        sort(res.begin(), res.end(), greater<int>());
        
        if(!flag)
        {
            return -1;
        }
        
        return max;
    }
};