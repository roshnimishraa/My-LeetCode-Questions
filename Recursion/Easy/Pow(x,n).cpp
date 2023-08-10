Logic : 
1. for n = even 
  if(n%2==0)  then ans=x*x and n=n/2
2. for n=odd  ans = ans*x and n = n-1

TC: O(N) 
SC : O(N)

 class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0;
      long long nn = n;
      
//    if n is -ve make +ve 
        if(nn < 0) {
            nn=-1 * nn;
        }
        
        while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
        //if n is -ve no then 1/-ve = +ve 
        if(n<0)
            ans= (double)(1.0) / (double)(ans);
     
      return ans;
    }
};
