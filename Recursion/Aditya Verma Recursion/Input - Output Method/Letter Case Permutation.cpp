class Solution {
public:
void solve(string s,string output,vector<string> &ans)
{
    if(s.length() == 0){
        ans.push_back(output);
        return;
    }
 
// if first char of input is alphabet 
    if(isalpha(s[0]))
    {
        string op1 = output;
        string op2 = output;
        
    op1.push_back(tolower(s[0]));
op2.push_back(toupper(s[0]));
        
        // input-> small 
    s.erase(s.begin()+0);
    solve(s,op1,ans);
    solve(s,op2,ans);
    }
//  if first char of input is digit 
    else{
    string op1 =output;
        op1.push_back(s[0]);
        s.erase(s.begin()+0);
    solve(s,op1,ans);
    }

}
    vector<string> letterCasePermutation(string s) {
    
        string output = "";
        vector<string> ans;
        solve(s,output,ans);
        return ans;
    }
};


---------------------------------------------------------------------------------------------------------------------------------------------------------------------
OR 

class Solution {
public:
void helper(string s,vector<string> &ans,int index)
{
    if(index>= s.length()){
    ans.push_back(s);
    return;
    }
if(isalpha(s[index]))
{
    s[index] = toupper(s[index]);
    helper(s,ans,index+1);
    s[index] = tolower(s[index]);
    helper(s,ans,index+1);

}
else{
    helper(s,ans,index+1);
}
}
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
    helper(s,ans,0);
    return ans;
    }
};
  
