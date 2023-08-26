class Solution {
public:
    
    static void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        for(int i=0; i<pairs.size(); i++)
        {
            int min = INT_MAX;
            int index = 0;
            for(int j=i; j<pairs.size(); j++)
            {
                if(min > pairs[j][1])
                {
                    min = pairs[j][1];
                    index = j;
                }
                // else if(min == pairs[j][1])
                // {
                //     if(pairs[index][1] > pairs[j][1])
                //     {
                //         min = pairs[j][0];
                //         index = j;
                //     }
                // }
            }
            
            swap(pairs[i][0], pairs[index][0]);
            swap(pairs[i][1], pairs[index][1]); 
        }
        
        for(int i=0; i<pairs.size(); i++)
        {
            cout << pairs[i][0] << " " << pairs[i][1] << endl;
        }
        cout << " ########### " << endl; 
        
        
        int count = 1;
        int j = 0;
        for(int i=1; i<pairs.size(); i++)
        {
            if(pairs[i][0] > pairs[j][1])
            {
                count ++;
                j = i;
            }
        }
        return count;
    }
};