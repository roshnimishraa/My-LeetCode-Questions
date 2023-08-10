Approach : 
1. given consider num char ignore spaces,0,string char 
2. to convert string to 
 s[i] - '0'
3. to get number 
1234 = 123*10 + 4 
  ans = ans*10+ (s[i] - '0')

  TC : O(N) 
SC : O(N) 
class Solution {
    int atoi(string s,int i,int sign,long long result)
    {
        if(sign*result >= INT_MAX){
            return INT_MAX;
        }
        if(sign*result <= INT_MIN){
            return INT_MIN;
        }
        if(i >= s.size() || s[i] < '0' || s[i] > '9'){
return  sign*result;
        }
        
        //recursive call
        result=atoi(s,i+1,sign,result*10+(s[i]-'0'));
        return result;
    }
public:
    int myAtoi(string s) {
        int result=0;
        int i=0,sign=1,n=s.size();
        
        while(i<n && s[i] == ' '){
            i++;
        }
        

        if (s[i] == '-')
            sign = -1, ++i;
        else if (s[i] == '+')
            ++i;
        
        return atoi(s,i,sign,result);
    }
};
