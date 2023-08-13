class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = (m * n) - 1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            int x = mid/n;
            int y = mid%n;
            
            if(matrix[x][y] == target)
            {
                return true;
            }
            
            if(matrix[x][y] > target)
            {
                end = mid-1;
            }
            
            if(matrix[x][y] < target)
            {
                start = mid+1;
            }
            
            cout << start << " " << end << endl;
        }
        
        return false;
        
    }
};