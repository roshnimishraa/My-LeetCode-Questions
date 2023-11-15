Problem Link : https://www.geeksforgeeks.org/problems/power-set4302/1

class Solution{
    void solve(string s,vector<string> &ans,string output)
    {
    if(s.length() == 0){
        if(output.size() !=0){
             ans.push_back(output); 
        }
      return;
    }
    
  string op1=output;
    string op2=output;
    op2.push_back(s[0]);
    s.erase(s.begin()+0);
    solve(s,ans,op1);
    solve(s,ans,op2);
    return;
    }
	public:
		vector<string> AllPossibleStrings(string s){
vector<string> ans;
string output="";
if(s.length()==0){
    return ans;
}
solve(s,ans,output);
sort(ans.begin(),ans.end());
return ans;
		}
};
