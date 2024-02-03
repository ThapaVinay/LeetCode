class Solution {
public:
    int minInsertions(string s) {
        
        stack <char> st;
        int count = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch == '(')
                st.push(ch);
            
            else if(ch == ')')
            {
                if(i+1 < s.size() && s[i+1] == ')')
                {
                    if(st.empty()) count ++;
                    else
                        st.pop();
                    i++;
                }
                else{
                    if(st.empty()) count += 2;
                    else
                    {
                        count ++;
                        st.pop();
                    }
                        
                }
            }
        }
        
        return count + st.size()*2;
    }
};