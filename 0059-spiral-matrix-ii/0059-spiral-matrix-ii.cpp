class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        // use simple array concept using initial row and column values
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int total = n * n;
        
        // intitial values
        int val = 1;
        int start_i = 0;
        int end_i = n;
        int start_j = 0;
        int end_j = n;
        
        while(val <= total)
        {   
            //first row
            for(int i=start_j; i<end_j; i++)
            {
                res[start_i][i] = val;
                val ++;
            }
            start_i++;

            //last column
            for(int i=start_i; i<end_i; i++)
            {
                res[i][end_j-1] = val;
                val ++;
            }
            end_j--;

            //last row
            for(int i=end_j-1; i>=start_j; i--)
            {
                res[end_i-1][i] = val;
                val ++;
            }
            end_i--;

            // first column
            for(int i=end_i-1; i>=start_i; i--)
            {
                res[i][start_j] = val;
                val ++;
            }
            start_j++;
        }
        
        return res;
    }
};