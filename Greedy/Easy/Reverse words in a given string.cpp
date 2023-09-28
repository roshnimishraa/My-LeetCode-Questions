TC : O(S) 
SC : O(S) 

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
    string ans="";
    string temp="";
    int n=S.length();
    for(int i=n-1;i>=0;i--)
    {
        if(S[i] == '.')
        {
            reverse(temp.begin(),temp.end());
            ans = ans+temp;
            ans.push_back('.');
            temp="";
        }
        else{
            temp.push_back(S[i]);
        }
    }
    // Corner case add first word
    reverse(temp.begin(),temp.end());
    ans = ans+temp;
    return ans;
    } 
};
