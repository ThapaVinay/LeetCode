class Solution {
public:
    
    static bool compare( vector<int>& a, vector<int>& b)
    {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    
    int maxEnvelopes(vector<vector<int>>& e) {
         /* first sort the vector based on the width
         and when width is same then sort based on descending height
        
         then just use LCS in the heights*/
        
        
        // sort the vector {O(nlogn)}
        
        sort(e.begin(), e.end(), compare);
        
        vector <int> n;
        for(int i=0; i<e.size(); i++)
        {
            n.push_back(e[i][1]);
        }
        
        
        /* using LCS on the width
         it is less then just append and if not then replace with the just greater value in the vector */
        
        vector <int> res;
        res.push_back(n[0]);
        for(int i=1; i<n.size(); i++)
        {
            if(res.back() < n[i])
            {
                res.push_back(n[i]);
            }
            else{
                for(int j=0; j<res.size(); j++)
                {
                    if(res[j] >= n[i])
                    {
                        res[j] = n[i];
                        break;
                    }
                }
            }
        }

        return res.size();

    }
};