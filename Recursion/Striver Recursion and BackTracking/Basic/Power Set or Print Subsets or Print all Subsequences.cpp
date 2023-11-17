Problem Link : https://www.geeksforgeeks.org/problems/power-set4302/1

/* 
Time Complexity : O(2^N)
Space Complexity : O(N)
*/

class Solution {
public:
void solve(vector<int>& nums,int index,vector<int> &output, vector<vector<int>> &ans)
{
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
//take 
output.push_back(nums[index]);
solve(nums,index+1,output,ans);
output.pop_back();
//not take 
solve(nums,index+1,output,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> output;
      int index =0;
    solve(nums,index,output,ans);
    sort(ans.begin(),ans.end());
    return ans;    
    }
};


---------------------------------------------------------------------------------------------------------------------------------------------------------------------

OR

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

