Approach: Map and Sorting
Here we store all same strings in a vector inside Hashmap.
We’ll take every string from strs in temp then sort that by character. Push the main string to the map.
Like these elements with the same character will push to the same vector of hashmap.
Then push all the vectors from map to ans.
  
Time complexity: O(n.klogk) /k is the length of string and n is the total no. of strings

Eg. Input: strs = ["eat","tea","tan","ate","nat","bat"]
  sol. 
  i. sort strs =["aet","aet","ant","aet","ant","abt]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
    
        unordered_map<string,vector<string>> umap;
        
    for(auto it :strs){
        string temp=it;
        
        sort(it.begin(),it.end());
        umap[it].push_back(temp);
    }
    for(auto it : umap){
     
        ans.push_back(it.second);
        
    }
        return ans;
    }
};
