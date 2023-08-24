class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector <string> res;
        
        string s = "";
        vector <int> temp;
        int count = 0;
        for(int i=0; i<words.size(); i++)
        {
            
            if((s+words[i]+" ").size()-1 > maxWidth)
            {
                if(count != 1 || s.size() > maxWidth)
                {
                    s.pop_back();
                }
                
                res.push_back(s);
                temp.push_back(count);
                count = 0;
                s = "";
            }
            s += words[i]+" ";
            count ++;
        }
        
        if(count != 1 || s.size() > maxWidth)
        {
            s.pop_back();
        }
        res.push_back(s);
        temp.push_back(count);
        
        // for(int i=0; i<temp.size(); i++)
        // {
        //     cout << temp[i] << " ";
        // }
        
        for(int i=0; i<res.size(); i++)
        {
            cout << res[i] << " " << res[i].size() << endl;
            int spaces = maxWidth - res[i].size();
            int count = 0;
            int rem = 0;
            if(temp[i] == 1 || i == res.size()-1)
            {
                count  = spaces;
                rem = 0;
            }
            else{
                count = spaces/(temp[i]-1);
                rem = spaces%(temp[i]-1);
            }
            
            string st = "";
            cout << count << " " << rem << endl;
            
            if(i == res.size()-1)
            {
                st += res[i];
                int k =0;
                while(k < count+rem)
                {
                    st += " ";
                    k++;
                }
            }
            else
            {
                for(auto ch : res[i])
                {
                    int k =0;
                    if(ch !=  ' ')
                    {
                        st += ch;
                    }
                    else
                    {
                        st += ch;
                        while(k < count)
                        {
                            st += " ";
                            k++;
                        }
                        if(rem > 0)
                        {
                            st += " ";
                            rem --;
                        }
                    }
                }
            }
            res[i] = st;
        }
        
        return res;
    }
};