class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        map <int, vector<int>> mp;
        
        for(int i=0; i<mat.size(); i++)
        {
            int start = 0;
            int end = mat[0].size();
            int mid = -1;

            while(start < end && mat[i][0] != 0)
            {
                mid = (start+end)/2;
                if(mid != mat[0].size()-1 && mat[i][mid] == 1 && mat[i][mid+1] == 0)
                {
                    break;
                }
                else if(mat[i][mid] == 1)
                {
                    start = mid+1;
                }
                else{
                    end = mid;
                }
            }
            
            if(mid == -1)
            {
                mp[0].push_back(i);
            }
            else{
                mp[mid+1].push_back(i);
            }
        }
        
        
        for(auto i: mp)
        {
            cout << i.first << "->";
            for(auto j: i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
        vector <int> res;
        for(auto pair: mp)
        {
            for(auto x : pair.second)
            {
                res.push_back(x);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
        
        return res;
    }
};