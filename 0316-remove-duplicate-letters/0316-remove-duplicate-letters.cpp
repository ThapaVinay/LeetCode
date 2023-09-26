class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack <char> st;
        vector <int> count(26, 0);
        vector <int> visited(26,0);
        
        // saving the last occurance
        for(int i=0; i<s.size(); i++)
        {
            count[s[i] - 'a'] = i;
        }
        
        st.push(s[0]);
        visited[s[0] - 'a'] = 1;
        for(int i=1; i<s.size(); i++)
        {
            char ch = s[i];
            if(visited[ch-'a'] == 0)
            {
                if(st.top() < ch)
                {
                    st.push(ch);
                    visited[ch - 'a'] = 1;
                }
                else {
                    while(!st.empty() && st.top() > ch && count[st.top() - 'a'] > i)
                    {
                        visited[st.top() - 'a'] = 0;
                        st.pop();
                    }
                    st.push(ch);
                    visited[ch - 'a'] = 1;
                }

            }
            
        }
        
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};