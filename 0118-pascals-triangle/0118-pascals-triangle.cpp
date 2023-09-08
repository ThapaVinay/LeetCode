class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> res;
        res.push_back({1});
        
        int i = 0;
        while(i < numRows-1)
        {
            vector <int> temp;
            temp.push_back(1);
            for(int j=0; j<res[i].size()-1; j++)
            {
                temp.push_back(res[i][j] + res[i][j+1]);
            }
            temp.push_back(1);
            
            res.push_back(temp);
            
            i++;
        }
        return res;
    }
};