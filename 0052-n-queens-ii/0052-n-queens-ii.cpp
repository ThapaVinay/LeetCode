class Solution {
public:
    
    int count = 0;
    
    // to check whether it is valid to put a queen in a particular cell
    bool isValid(int row, int col, vector <vector<bool>> &matrix)
    {
        
        // checking in the same column
        for(int i=0; i<=row; i++)
        {
            if(matrix[i][col])
                return  false;
        }
        
        // checking left diagonal 
        int i = row, j = col;
        while(i >=0 && j>=0)
        {
            if(matrix[i][j])
                return false;
            i--;
            j--;
        }
        
        // checking right diagnol
        i = row, j = col;
        while(i >=0 && j<matrix.size())
        {
            if(matrix[i][j])
                return false;
            i--;
            j++;
        }
        
        return true;
    }
    
    void recur(int n, int row, vector <vector<bool>> &matrix)
    {
        if(row == n)
        {
            count ++;
            return;
        }
        
        // iterating columns to find the valid column to put the queen
        for(int col = 0; col < n; col++)
        {
            if(isValid(row, col, matrix))
            {
                matrix[row][col] = true;
                recur(n, row+1, matrix);
                matrix[row][col] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        
        // just go row-wise and place a queen in each row
        
        vector <vector<bool>> matrix(n, vector<bool>(n, false));
        
        recur(n, 0, matrix);
        
        return count;
    }
};