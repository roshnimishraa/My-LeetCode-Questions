/* TC : O(2^n * n)
   SC : O(n) */


class Solution {
public:
bool isPalindrome(string &s,int start,int end)
{
    while(start<=end){
        if(s[start] != s[end])

            return false;
            start++;
            end--;
   }
    return true;
}
void solve(int index,string &s,vector<string> &output,    vector<vector<string>> &ans){
    // base case 
    if(index == s.length()){
        ans.push_back(output);
        return;
    } 

// check whether the partition is valid palindrom or not 
for(int i=index;i<s.length();i++){
    if(isPalindrome(s,index,i)==true)
{
// if it is a palindrom then store substring from index to i
    output.push_back(s.substr(index,i-index+1));
    solve(i+1,s,output,ans);
    // backtrack 
    output.pop_back();
}
} 
}
    vector<vector<string>> partition(string s) {
 vector<vector<string>> ans;
 vector<string> output;

 solve(0,s,output,ans);
 return ans;
    }
};
