class Solution {
public:
    
    void addResult(vector<vector<string>> &res, vector <vector<int>> &valid)
    {
        vector <string> temp;
        for(int i=0; i<valid.size(); i++)
        {
            string s = "";
            for(int j=0; j<valid.size(); j++)
            {
                if(valid[i][j] == 1)
                {
                    s += 'Q';
                }
                else{
                    s += '.';
                }
            }
            temp.push_back(s);
        }
        res.push_back(temp);
    }

    bool isValid(int row, int col, vector <vector<int>> &valid)
    {
        int i = col;
        while(i>=0)
        {
            if(valid[row][i] == 1)
                return false;
            i--;
        }
        
        // diagnonals
        i = row;
        int j = col;
        while(i >=0 && j >=0)
        {
            if(valid[i][j] == 1)
                return false;
            
            i--;
            j--;
        }
        
        i = row;
        j = col;
        while(i < valid.size() && j >=0)
        {
            if(valid[i][j] == 1)
                return false;
            
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void solveRec(int n, vector <vector<int>> &valid, vector<vector<string>> &res, int col)
    {
        if(col == n)
        {
            addResult(res, valid);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isValid(row, col, valid))
            {
                valid[row][col] = 1;
                solveRec(n, valid, res, col+1);
                valid[row][col] = 0;
            }
        }
    }

    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        
        vector <vector<int>> valid(n, vector<int>(n,0));
        
        solveRec(n, valid, res, 0);
        
        return res;
    }
};