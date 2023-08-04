To find: all possible letter combinations that the number could represent
Approach : Backtracking 
Corner Case : index >= n and string can be empty 

Time Complexity : O(3^N × 4^M) where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to
    it and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

Space Complexity : O(3^N × 4^M) where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to
    it and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

  
1. the value given in string to get the corresonding from index of int type :
    int number = str[index]-'0'
  Now to get the corresponding value of index 2 -> abc,3->def 
  string values = mapping[number];
2. Explore till values length 

eg. Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

  class Solution {
    void helper(int index,string str,string&output,string mapping[],vector<string> &ans)
    {
        int n=str.size();
        if(index >= n){
            ans.push_back(output);
            return;
        }
      
//Since ip is str type "23" to point index value we have to convert into //integer         
   int num =str[index]-'0';  
        
//to get the correspoing number value 2->abc
        string values = mapping[num]; 
        
for(int i=0;i<values.length();i++)
{
   
 output.push_back(values[i]);
    helper(index+1,str,output,mapping,ans);
    output.pop_back();
    
}
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        if(digits.length()==0){
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
      helper(index,digits,output,mapping,ans);
        return ans;
    }
};
