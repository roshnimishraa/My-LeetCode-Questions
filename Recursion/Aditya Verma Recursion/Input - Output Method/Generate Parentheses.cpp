Generate All Balanced Parenthesis 

Problem Link : https://leetcode.com/problems/generate-parentheses/description/

Observation 
1. Open bracket choice 
     if open != 0 // got balanced parenthesis 
2. Close bracket choice 
  if( close > open)  

TC : O(2^N)
SC : O(N) 

class Solution {
public:
void solve(int open,int close,string output,vector<string> &ans){
    if(open == 0 && close==0){
        ans.push_back(output);
        // return at leaf node
    return;
    }
// opening bracket choice
if(open !=0){
    string op1 = output;
op1.push_back('(');
solve(open-1,close,op1,ans);
}
// closing bracket choice
if(close > open){
string op2 = output;
op2.push_back(')');
solve(open,close-1,op2,ans);
}

}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=n;
        int close=n;
        string output ="";
    solve(open,close,output,ans);
return ans;
    }
};
