//Approach-2 (Using stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back)
//S.C : O(n) stack

class Solution {
public:
    string removeDuplicateLetters(string s) {
                int n = s.length();
        vector<int> lastIndex(26);
        vector<bool> vis(26,false);
string result;
stack<char> st;
    for(int i=0;i<n;i++)
    {
        char ch = s[i];
        lastIndex[ch-'a']=i;
    }

for(int i=0;i<n;i++)
{
    char ch =s[i];
    int index = ch-'a';
    
if(vis[index] == true) continue;

while(!st.empty() && s[i] < st.top() && 
lastIndex[st.top() - 'a'] > i)
{
    vis[st.top()-'a'] = false;
   st.pop();

}
st.push(s[i]);
vis[index]=true;
}

while(!st.empty())
{
    result.push_back(st.top());
    st.pop();
}
 reverse(begin(result), end(result));
        
return result;
    }
};
