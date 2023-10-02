class Solution {
public:
    bool winnerOfGame(string colors) {
        
        // count consecutive A's and find total possible moves
        
        int count_a = 0, count_b = 0;
        char curr_ch;
        
        int curr_count = 0;
        colors += "C";
        
        for(auto ch: colors)
        {
            if(curr_ch != ch)
            {
                if(curr_count > 2)
                {
                    if(curr_ch == 'B')
                    {
                        count_b += curr_count - 2;
                    }else{
                        count_a += curr_count - 2;
                    }
                }
                
                curr_count = 0;
                curr_ch = ch;
            }
            curr_count ++;
        }
        
        if(count_b > count_a)
        {
            return false;
        }
        else if(count_b == count_a)
        {
            return false;
        }
        else
            return true;
    }
};