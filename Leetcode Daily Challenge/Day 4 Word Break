Brute Force: Using Recursion gives TLE

Efficient Approach : Dynamic Programming (Top-Down Approach)

class Solution {
    // top down approach
    int dp[301];
 bool helper(int i,string s,unordered_set<string> &wordDict)
    {
        if(i==s.size()) return true;
      string temp;
       if(dp[i] != -1) return dp[i];
            for(int j=i;j<s.size();j++){
       temp += s[j];
    if(wordDict.find(temp) != wordDict.end()){
        if(helper(j+1,s,wordDict)) return dp[i]=1;
    }
        }
     return dp[i]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
     
        unordered_set<string> st;
        memset(dp,-1,sizeof dp);
        for(auto x : wordDict){
            st.insert(x);
        }
        
        return helper(0,s,st);
    }
};
