TC : O(m + n) 
SC : O(1) 
Approach : 
1. if s[i] is present in t[j] then do i++ 
2. move j++ every time 
3. if i == m that means all character are found in t[j] therefore return true
else return false 


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        
    int i=0,j=0;

 while(i<m && j<n)
 {
     if(s[i] == t[j]) {
         i++;
      
     }
        j++;
 } 
        if(i==m) return true;
         return false;
    }
};

----------------------------------------------------------------------------------------------------------------------------------

Follow - Up Question : 
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if
it has its subsequence. In this scenario, how would you change your code?

  class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
// {char,{no of indices on which char occur}}
        
    map<char,vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        mp[t[i]].push_back(i);
    }
        
    int prev =-1;
        
// now check if s[i] is present in map or not 
    for(int i=0;i<m;i++)
    {
        char ch = s[i];
        
    if(mp.find(ch) == mp.end())
    {
        return false;
    }

// now if a a in s[i] then to find second a in mp we have to apply
    // binary search or upper bound 
    vector<int> indices = mp[ch];
        // smallest greater value than prev
    auto it = upper_bound(indices.begin(),indices.end(),prev);
        
//     if not found in mp
    if(it == indices.end()) return false;
        
//    if found in mp
    prev = *it; //to get value 
        
    }
    return true;    
    }
};

