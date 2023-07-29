Brute Force(Naive) Approach : Use Count and do not push 1st bracket(outermost) in res

Time complexity: O(n) //One pass
Space complexity: O(n) //For resultant string

   string removeOuterParentheses(string s)
    {
        int count = 0;
        string ans;
        for(char i:s)
        {
            if(i == '(')
            {
                if(count > 0)
                {
                    ans += i;
                }
                count++;
            }
            else
            {
                if(count > 1)
                {
                    ans += i;
                }
                count--;
            }
        }
        return ans;
    }
};
---------------------------------------------------------------------------------------------------------------------------------------

  Efficient Approach : Stack 
  1. insert open bracket and not include in ans 
  2. for close bracket search for open bracket and pop if close bracket is for inner bracket then include in ans 
and it is for outer bracket then pop from stack not include in ans

     Time Complexity : O(N)
     Space Complexity : O(1) 
    
    class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        
        for(int i=0;i<s.length(); i++){
            char ch = s[i];
            if(ch == '(')
            {
                
                if(st.size() > 0)
                {
                    ans += '(';
                }
                st.push(ch);
            }
            else{
                //close bracket 
                st.pop();
                if(st.size() > 0){
                ans += ')';
                }
            }
        }
        return ans;
    }
};
  
