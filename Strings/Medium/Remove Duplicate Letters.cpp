Problem Link : https://tinyurl.com/27qbceh3

TC : O(N) 
SC : O(26) ~ O(1) 

Approach : 
1. Taken a vis vector array of 26 size,lastIndex,result to store ans
2. Calculate the lastIndex of every character in a string 
3. If a character will come after the current char then pop out 
else store in result
4. mark vis as true
5. return result

class Solution {
public:
    string removeDuplicateLetters(string s) {
                int n = s.length();
        vector<int> lastIndex(26);
        vector<bool> vis(26,false);
string result;
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

while(result.length() > 0 && s[i] < result.back() && 
lastIndex[result.back() - 'a'] > i)
{
    vis[result.back()-'a'] = false;
    result.pop_back();

}
result.push_back(s[i]);
vis[index]=true;
}
return result;
    }
};
