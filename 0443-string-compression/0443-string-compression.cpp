class Solution {
public:
    int compress(vector<char>& chars) {
        
        int i=0, j=0, k =0;
        
        while(i < chars.size())
        {
            j = i+1;
            
            while(j < chars.size() && chars[i] == chars[j])
                j++;
            
            int count = j - i;
            
            chars[k++] = chars[i];
            if(count > 1)
            {
                string temp = to_string(count);
                for(auto x: temp)
                {
                    chars[k++] = x;
                }
            }
            
            i = j;
        }
        
        return k;
    }
};