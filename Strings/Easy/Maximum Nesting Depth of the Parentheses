Better Approach : stack 
TC : O(N) 
SC : O(N) 

Input: s = "(1)+((2))+(((3)))"
Output: 3

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
     int maxi =0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else if(ch==')'){
            int x=st.size();
            maxi = max(maxi,x);
                st.pop();
            }
        }
        return maxi;
    }
};

Efficeint Approach : 
maxi & curr 
TC :  O(N)
SC : O(1) 

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int curr =0;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            
            if(ch == '(')
                curr++;
                ans = max(ans,curr);
            
            if(ch == ')')
                curr--;
        }
return ans;
    }
};
