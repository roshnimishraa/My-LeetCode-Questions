Approach : Sliding window and unordered_map
TC : O(N)
SC :O(1) 
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> umap;
        int i=0,j=0;
int maxCount=0; // no of repeating 
        int ans=0;
    while(j<s.length())
    {
        umap[s[j]]++;
         maxCount=max(maxCount,umap[s[j]]);
      
        int windowSize = j-i+1;
        if(windowSize - maxCount > k){
            umap[s[i]]--;   //slide the window    
        i++;
        }
        ans = max(ans,j-i+1);
      j++;
    }
          return ans;
    }
};
