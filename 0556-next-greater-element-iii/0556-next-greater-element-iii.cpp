class Solution {
public:
    int nextGreaterElement(int n) {
        // check from last if we have a integer greater than that in the right side
        // if there is then just swap and sort the array after that index
        
        string s = to_string(n);
        
        int size = s.size();
        
        // find the greater element 
        int i, j=size-1;
        for(i=size-2; i>=0; i--)
        {
            if(s[i] >= s[j])
            {
                j--;
            }
            else{
                while(j < size && s[i] < s[j])
                {
                    j++;
                }
                j--;
                break;
            }
            
        }
        
        if( i < 0)
            return -1;
        
        // swap them
        swap(s[i], s[j]);
        
        // sort the array from i+1
        sort(s.begin() + i+1, s.end());
        
        long res = stoll(s);
        
        if(res > INT_MAX)
            return -1;
        
        return res;
        
    }
};