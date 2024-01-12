class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int mid = s.size()/2;
        set <char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count1 = 0, count2 = 0;
        
        for(int i=0; i<mid; i++)
        {
            if(st.contains(s[i]))
            {
                count1 ++;
            }
        }
        
        for(int i=mid; i< s.size(); i++)
        {
            if(st.contains(s[i]))
            {
                count2 ++;
            }
        }
        
        return count1 == count2;
    }
};