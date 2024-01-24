class Solution {
public:
    int longestValidParentheses(string s) {
        
        // use two stacks one for saving character and one for the last index you think will create problem in making a valid parentheses
        
        stack <char> st;
        stack <int> index;
        
        int ans = 0;
        index.push(-1);
        
        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            
            if(ch == '(')
            {
                st.push(ch);
                index.push(i);
            }
            else 
            {
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    index.pop();
                    ans = max(ans, i - index.top());
                }
                else{
                    index.push(i);
                }
                
            }
            
        }
        
        return ans;
    }
};