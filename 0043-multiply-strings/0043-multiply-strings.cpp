class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        
        int n = num1.size();
        int m = num2.size();
        
        string prev = "";
        int val = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            string s = "";
            int carry = 0;
            
            int temp1 = val;
            while(temp1--)
                s += '0';
            
            // for multiply
            for(int j=m-1; j>=0; j--)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                
                int mul = a*b + carry;
                carry = 0;
                
                carry = mul/10; 
                mul = mul%10;
                
                s += mul + '0';
            }
            
            if(carry)
            {
                s += carry + '0';
            }
            
            reverse(s.begin(), s.end());
            
            // for addition
            string temp = "";
            if(prev.size() != 0)
            {
                carry = 0;
                int k = s.size()-1;
                int l = prev.size()-1;
                
                for(; k>=0 && l>=0; k--, l--)
                {
                    int a = s[k] - '0';
                    int b = prev[l] - '0';
                    
                    int add = a + b + carry;
                    carry = 0;
                    
                    carry = add/10; 
                    add = add%10;
                    
                    temp += add + '0';  
                }
                
                while(k >= 0)
                {
                    int add = (s[k] - '0') + carry;
                    carry = 0;
                    
                    carry = add/10; 
                    add = add%10;
                    
                    temp += add + '0'; 
                    k--;
                }
                
                while(l >= 0)
                {
                    int add = (prev[l] - '0') + carry;
                    carry = 0;
                    
                    carry = add/10; 
                    add = add%10;
                    
                    temp += add + '0'; 
                    l--;
                }
                 
                if(carry)
                {
                    temp += carry + '0';
                }
                
                reverse(temp.begin(), temp.end());
                
                prev = temp;
                
            }
            else{
                prev = s;
            }

            val++;
        }
        
        return prev.substr(0, prev.size()-1);
    }
};