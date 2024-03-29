class Solution {
public:
    
//     double power(double x, int n)
//     {
//         if(n == 1)
//         {
//             return x;
//         }
        
//         double res = x * power(x,n-1);
//         return res;
//     }
    
    double myPow(double x, int n) {
    if(n<0) return 1/x * myPow(1/x, -(n+1));
    if(n==0) return 1;
    if(n==2) return x*x;
    if(n%2==0) return myPow( myPow(x, n/2), 2);
    else return x*myPow( myPow(x, n/2), 2);
}
};