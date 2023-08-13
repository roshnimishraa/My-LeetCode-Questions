Approach : do different ways of partitioning in an array and include in ans vector if it is palindrome 

Time Complexity: O( (2^n) *k*(n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)
Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).


class Solution {
   
    void helper(int index,string s,vector<string> &output,
               vector<vector<string>> &ans)
    {
        if(index==s.size()){
            ans.push_back(output);
            return;
        }
    for(int i=index;i<s.size();i++){
//   include if its palindrom 
        if(isPalindrome(s,index,i)){
//     s.substr(index,i-index+1) from index to partition 
            output.push_back(s.substr(index,i-index+1));
            helper(i+1,s,output,ans);
            output.pop_back();
        }
    }
    }
    
 bool isPalindrome(string s,int start,int end){
     while(start <= end){
         if(s[start++] != s[end--])
             return false;
     }
     return true;
 }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int index=0;
        helper(index,s,output,ans);
        return ans;
    }
};
