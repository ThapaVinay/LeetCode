class Solution {
public:
    
    bool recur(vector<vector<char>>& board, string &word, int i, int j, vector<vector<bool>> & visited, int k)
    {
        if(k == word.size())
            return true;
        
        // row and column size
        int r = board.size();
        int c = board[0].size();
        
        if(i >= r || i < 0 || j >= c || j < 0)
            return false;
        
        // pruning to discard the characters
        if(board[i][j] != word[k])
            return false;
        
        // to not visit the same word twice
        if(visited[i][j])
            return false;
        
        visited[i][j] = 1;
        
        // go right
        bool right = recur(board, word, i, j+1, visited, k+1);
        
        // go down
        bool down = recur(board, word, i+1, j, visited, k+1);
        
        // go left
        bool left = recur(board, word, i, j-1, visited, k+1);
        
        // go top
        bool top = recur(board, word, i-1, j, visited, k+1);
        
        visited[i][j] = 0;
        
        return (left || right || top || down);
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int r = board.size();
        int c = board[0].size();
        
        // to check the visited cells
        vector<vector<bool>> visited(r, vector<bool>(c, 0));
        
        // iterate through each cell and find if the word is possible starting from each cell
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                // pruning
               if(board[i][j] != word[0])
                   continue;
                
               if(recur(board, word, i, j, visited, 0))
               {
                   return true;
               }
            }
        }
        
        return false;
    }
};