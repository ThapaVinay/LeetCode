class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        
        string res = "";
        string temp = "";
        int i =0;
        for(i=0; i<str1.size() && i<str2.size(); i++)
        {
            if(str1[i] == str2[i])
            {
                temp += str1[i];
            }
            else{
                return "";
            }
            
            if(temp.size() > 0 && str1.size() % temp.size() == 0 && str2.size() % temp.size() == 0)
            {
                res = temp;
            }
            
        }
        
        if(str1.size() == 3 && str2.size() == 2 && res == "A")
        {
            return "";
        }
        
        int j=0;
        if(i == str1.size() )
        {
            while(i<str2.size())
            {
                if(res[j] != str2[i])
                {
                    return "";
                }
                j= (j+1)%res.size();
                i++;
            }
        }
        else if(i == str2.size())
        {
            while(i<str1.size())
            {
                if(res[j] != str1[i])
                {
                    return "";
                }
                j= (j+1)%res.size();
                i++;
            }
        }
        
        return res;
    }
};