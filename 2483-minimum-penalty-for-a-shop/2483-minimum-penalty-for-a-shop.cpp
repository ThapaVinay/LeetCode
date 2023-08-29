class Solution {
public:
    int bestClosingTime(string customers) {
        
        int total = 0;
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i] == 'Y')
            {
                total += 1;
            }
        }
        
        int min = total ;
        int index = -1;
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i] == 'Y')
            {
                total -= 1;
            }
            else{
                total += 1;
            }
            
            if(min > total)
            {
                min = total;
                index = i;
            }
        }
        return index+1;
    }
};