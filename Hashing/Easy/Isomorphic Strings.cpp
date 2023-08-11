Approach : Hashing (two unordered map) 
  TC : O(N) 
SC : O(N) 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,bool> mp2;
        
    for(int i=0;i<s.length(); i++){
        if(mp1.find(s[i])  != mp1.end()) //if present 
        {
            if(mp1[s[i]] != t[i])  
            {
                return false;
        }
        }     
    
  else{
      if(mp2.find(t[i]) != mp2.end()) {
          return false; 
    }else{
          mp1[s[i]] = t[i];
          mp2[t[i]] = true;
      }
  }
    }
       return true;
    }
};
