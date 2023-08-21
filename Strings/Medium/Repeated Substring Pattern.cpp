Important question
For number n max no. of divisor can be 2*root n

TC : O(N * root n) 

Efficient Approach : 
Traverse from n/2 to length 1 

  
  class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        
    for(int l = n/2; l>=1; l--){
    
    if(n % l == 0){
        
        int time = n/l;
        string newString ="";
        
        string patterns = s.substr(0,l);
        
        while(time--){
            newString +=patterns;
        }
        if(newString == s) return true;
    }
    }
        return false;
    }
};
