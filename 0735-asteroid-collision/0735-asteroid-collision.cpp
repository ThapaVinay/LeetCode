class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector <int> res;
        
        res.push_back(a[0]);
        
        for(int i=1; i<a.size(); i++)
        {
            bool flag = true;
            while(res.size() > 0 && res.back() * a[i] < 0 && res.back() > 0)
            {
                if(abs(res.back()) < abs(a[i]))
                {
                    res.pop_back();
                }
                else if(abs(res.back()) == abs(a[i]))
                {
                    res.pop_back();
                    flag = false;
                    break;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                res.push_back(a[i]);
            }
            
            // for(auto x:res)
            // {
            //     cout << x << " ";
            // }
            // cout << endl;
            
            
        }
        return res;
    }
};