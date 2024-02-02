class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string val = to_string(low);
        vector <int> res;
        int size = val.size();
        
        while(low < high)
        {    
            int limit = 9-size+1;
            
            if(limit <= 0)
                break;
            
            for(int i=0; i<limit; i++)
            {
                int j = i+1;
                for(int k=0; k<size; k++)
                {
                    val[k] = j++ + '0';
                }

                if(low > stoi(val))
                    continue;
                
                low = stoi(val);
                
                if(low <= high)
                {
                    res.push_back(low);
                }
                else
                    return res; 
            }
            size++;
        }
        
        return res;
    }
};