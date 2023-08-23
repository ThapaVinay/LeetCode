class Solution {
public:
    
    static bool compare(const pair<char,int> &a,const pair<char,int> &b)
    {
        return a.second > b.second;
    }
    
    string reorganizeString(string s) {
        
        string res= ""+s;
        
        map<char, int> v;
        
        // making the array
        for(auto ch : s)
        {
            int temp = (int)ch - 97;
            v[ch] += 1;
        }
        
        vector<pair<char,int>> sorted(v.begin(), v.end());
        
        sort(sorted.begin(), sorted.end(), compare);
        
        vector <int> vt(sorted.size());
        vector <char> ch(sorted.size());
        int i=0;
        for(auto &a: sorted)
        {
            vt[i] = a.second;
            ch[i] = a.first;
            // cout << a.first << " " << a.second << endl;
            i++;
        }

        int j =0;
        for(int i=0 ;i<s.size();i+=2)
        {
            while(vt[j] == 0)
            {
                j++;
            }
            res.at(i) = ch[j];
            vt[j]--;
        }
        
        for(int i=1; i<s.size(); i+=2)
        {
            while(vt[j] == 0)
            {
                j++;
            }
            res.at(i) = ch[j];
            vt[j]--;
        }
        
        
            
            
 
        
//         while(res.size() < s.size())
//         {
            
//             for(int i=0; i<vt.size(); i++)
//             {
//                 // cout << vt[i] << " " << ch[i] << endl;
//                 int first=0, second=0;
//                 if(vt[i] != 0)
//                 {
//                     res += ch[i];
//                     first = --vt[i];
//                 }
                
//                 int temp = i;
//                 i++;
//                 // cout << vt[i] << " " << ch[i] << endl;
//                 while(i<vt.size() && vt[i] == 0)
//                 {
//                     i++;    
//                 }
//                 // cout << vt[i] << " " << ch[i] << endl;

//                 if(i < vt.size() && vt[i] != 0)
//                 {
//                     res += ch[i];
//                     second = --vt[i];
//                     if(first > second)
//                     {
//                         i = temp-1;
//                     }
//                 }
                
                
//             }
//         }
        cout << res;
        for(int i=0; i<res.size()-1; i++)
        {
            if(res[i] == res[i+1])
            {
                return "";
            }
        }
        return res;
    }
    
};