class Solution {
public:
    string decodeString(string s) {
        
        stack <char> st;
        
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch != ']')
            {
                st.push(ch);
            }
            else{
                string val = "";
                while(st.top() != '[')
                {
                    val += st.top();
                    st.pop();
                }
                st.pop();
                
                string n = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    n += st.top();
                    st.pop();
                }
                
                reverse(n.begin(), n.end());
                int no = stoi(n);
                
                while(no--)
                {
                    for(int j=val.size()-1; j>=0; j--)
                    {
                        st.push(val[j]);
                    }
                }
            }
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};