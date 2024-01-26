class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        // initial initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        vector <int> ans;
        
        int count = row * col;
        
        while(count > 0)
        {
            // starting row
            for(int i=startingCol; i<=endingCol && count > 0; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count --;
            }
            startingRow++;
            
            // ending column
            for(int i=startingRow; i<=endingRow && count > 0; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count --;
            }
            endingCol--;
            
            // ending row
            for(int i=endingCol; i>=startingCol && count > 0; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count --;
            }
            endingRow--;
            
            // starting column
            for(int i=endingRow; i>=startingRow && count > 0; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count --;
            }
            startingCol++;
        }
        
        return ans;
    }
};