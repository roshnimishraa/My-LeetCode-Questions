Approach : divisibility rule for odd and check from right 
To find : largest odd string 

TC : O(N) 
SC : O(1) 
Eg. "343618"
o/p : "34361"

class Solution {
public:
    string largestOddNumber(string num) {
     
        for(int i=num.size() - 1;i>=0;i--){
            if(num[i] % 2 == 0){
                num.pop_back();
           
            }
            else break;
        }
        return num;
    }
};
