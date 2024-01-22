class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        if(chars.size() == 1)
        {
            return 1;
        }
        
        char ch = '\0';
        
        int count = 0;
        
        int j = 0;
        
        for(int i=0; i<chars.size(); i++)
        {
            if(ch == '\0')
            {
                ch = chars[i];
                count = 1;
            }
            else if(ch == chars[i]){
                count ++;
            }
            else{
                chars[j++] = ch;
                
                string temp = "";
                if(count > 1)
                {
                    temp += to_string(count);
                }
            
                reverse(temp.begin(), temp.end());
                
                for(int k=temp.size()-1; k>=0; k--)
                {
                    chars[j++] = temp[k];
                }
                
                ch = chars[i];
                count = 1;
            }
        }
        
        if(ch != '\0')
        {
            chars[j++] = ch;
                
            string temp = "";
            
            if(count > 1)
            {
                temp += to_string(count);
            }
            
            reverse(temp.begin(), temp.end());
            
            for(int k=temp.size()-1; k>=0; k--)
            {
                chars[j++] = temp[k];
            }
        }
        
        return j;
    }
};