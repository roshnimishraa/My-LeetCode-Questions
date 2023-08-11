Approach : Recursion 
 Eg. n=3 open=3 close=3 
  case 1: open == close use open bracket 
  ('(',2,3) open-1
  case 4 use either open bracket or close bracket 
('((',1,3) 
('(((',0,3)
  case 2 : open ==0 use close bracket 
('((()',0,2) 
('((())',0,1) 
('((()))',0,0) 
corner case when open == 0 && close == 0 push it into ans 

Time complexity: O(2^n), as there are 2^n possible combinations of ‘(‘ and ‘)’ parentheses.
Auxiliary space: O(n), as n characters are stored in the str array.
  
class Solution {
    void helper(string output,int open,int close,vector<string> &ans)
    {
//     corner case
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
    //case 1: open == close push open bracket
    if(open == close){
     string op1 = output;
    op1.push_back('(');
    helper(op1,open-1,close,ans);
    }
//      case: 2
    else if(open == 0){
//use close bracket 
    string op1=output;
    op1.push_back(')');
  helper(op1,open,close-1,ans);
        
    }
  // case 3
    else if(close == 0){
//use open bracket 
    string op1=output;
        op1.push_back('(');
    helper(op1,open-1,close,ans);
    }
//      case 4
    else {
// all the possiblities like ('((',1,3) n=3 use either open or bracket 
    string op1=output;
    string op2 = output;
    op1.push_back('(');
    op2.push_back(')');
    helper(op1,open-1,close,ans);
    helper(op2,open,close-1,ans);
    
    }
    }
public:
    vector<string> generateParenthesis(int n) {
    vector<string> ans;
        string output="";
        int open = n;
        int close = n;
    helper(output,open,close,ans);
        return ans;
    }
};
