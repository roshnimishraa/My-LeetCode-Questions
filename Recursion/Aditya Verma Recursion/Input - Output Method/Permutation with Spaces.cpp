class Solution{
public:
void helper(int index,string s,string curr,vector<string> &ans)
{
    if(index>= s.size()){
        ans.push_back(curr);
        return;
    }
    
    // include space 
    helper(index+1,s,curr+" "+s[index],ans);
    
    // exclude
    helper(index+1,s,curr+s[index],ans);
}
    vector<string> permutation(string S){
        vector<string> ans;

        string curr;
        curr += S[0];
        // 1 based indexing 
    helper(1,S,curr,ans);
        return ans;
    }
};
