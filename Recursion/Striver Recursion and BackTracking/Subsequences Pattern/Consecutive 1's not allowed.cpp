Problem Link : https://tinyurl.com/yopv8z6h

>> If the last digit is 0 then there is two possibilites 
1. append 0 
2. append 1 

>> If the last digit is 1 then there is only one possibility since consecutive one's are not allowed 
1. append 0 

Time complexity: O(2^K) where K is the size of the binary string. This is due to the fact that the algorithm recursively generates all
possible binary strings of length K.
Auxiliary space: O(K), since we are using a string array of size K to store the binary string.


class Solution{
public:
void helper(int n,string output,int lastdigit,vector<string> &ans){
    if(n == 0){
        ans.push_back(output);
        return;
    }
    // append 0
    helper(n-1,output+"0",0,ans);
    
    // append 1 if the last digit is 0 
    if(lastdigit == 0){
        helper(n-1,output+"1",1,ans);
    }
}
    vector<string> generateBinaryStrings(int num){
    vector<string> ans;
    string output="";
    int lastdigit =0;
    helper(num,output,lastdigit,ans);
    return ans;
    }
};
