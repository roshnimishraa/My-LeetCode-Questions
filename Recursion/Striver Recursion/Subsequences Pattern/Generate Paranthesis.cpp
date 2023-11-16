Approach : Recursion 

Time complexity: O(2^N)
Space complexity: O(N)
  
class Solution {
public:
void helper(int open,int close,string output,vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }
if(open !=0){
    string op1 = output;
    op1.push_back('(');
    helper(open-1,close,op1,ans);
}
if(close > open){
    string op2 = output;
    op2.push_back(')');
    helper(open,close-1,op2,ans);
}
}
    vector<string> generateParenthesis(int n) {
        int open =n;
        int close=n;
    vector<string> ans;
    string output="";
    helper(open,close,output,ans);
    return ans;
    }
};
