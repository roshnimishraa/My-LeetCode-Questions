Approach : Recursion and Backtracking 

TC : O(4^n) 
SC : O(n) 

class Solution {
public:
void helper(int index,string num,string mapping[],string output,vector<string> &ans)
{
    //base case 
    if(index == num.size()){
        ans.push_back(output);
        return;
    }

// num->index->mapping 
int number = num[index]-'0';
string values = mapping[number];
for(int i=0;i<values.length();i++){
    output.push_back(values[i]);
    helper(index+1,num,mapping,output,ans);
    // backtracking
    output.pop_back();
}
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
if(digits.length() == 0){
    return ans;
}
helper(0,digits,mapping,output,ans);
return ans;
    }
};
