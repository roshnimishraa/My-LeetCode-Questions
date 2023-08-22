Time Complexity :  O(log(columnNumber)) base 26

Eg. columnNumber = 26
  sol 
  colNo = 25
  rem = 25 % 26 -> 25 -> Y -> 0%26 = 0 loop break
  colNo = 25/26 -> 0 
  ans += 'a' + rem => 26 =Z


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output;
        
        while(columnNumber > 0)
        {
            columnNumber--;
            
        int rem = columnNumber%26;
            columnNumber = columnNumber/26;
            output += 'A'+ rem;
            
        }
        //reverse print from right to left
        reverse(output.begin(),output.end());
        return output;
    }
};

why I do columnNumber-- because for eg. if input = 26
   rem = 0 loop break 
   colNo = 26/26 = 1 
  which is not giving correct output

  
