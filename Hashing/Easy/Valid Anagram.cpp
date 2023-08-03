Brute Force Approach : Using Sorting 

Time Complexity: O(N * logN), For sorting.
Auxiliary Space: O(1) as it is using constant extra spac

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : using hashing 
Time Complexity: O(N)
Auxiliary Space: O(N), Hashmap uses an extra space 

Logic : We can the count of s[i] in umap and if it is in t[i] then we descrease the count of t[i] 
if it is anagram then count =0 return true else false

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> umap;
        
    if(s.length() != t.length()) return false;
        
    for(int i=0;i<s.length();i++){
        
        umap[s[i]]++;
        umap[t[i]]--;
    }
        for(auto it:umap){
            if(it.second) return false;
        }
        return true;
    }
};
