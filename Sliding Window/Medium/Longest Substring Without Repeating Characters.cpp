Brute Force : 
TC : O(N)^3
SC :O(N) 
Logic : using three loops i,j,k 
k= i to j

Better Approach :
TC : O(2N) traversing left unneccessary to reach its position 
SC : O(1) set is used but with n=256 which is very small therefore O(1) 

Logic :  left=0, right=0, len=0 [len = right - left + 1]
1. insert element into set if it is unique and do right++
2. if duplication element found while traversing array then remove from set and do left++ and right++ 
3.  return max len(max of substring) 
4. Storing occurences of character in map



int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
-------------------------------------------------------------------------------------------------------------------------------------

  Efficient Approach : 
TC : O(N) -> use unordered map 
SC : O(1) 
            window size = right - left + 1
  Logic :  All unique character = window size 
1. store unique element with index 
2. if duplicate element found then replace index of that element in umap on which index duplicate element occur do left++
3. consider range till left -> right if duplicate occurs before it change index and do not update left
4 return max len = right - len + 1

  TC : O(N) 
SC : O(1) 
  
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int left=0;
        int right=0;
        int ans = INT_MIN;
    unordered_map<char,int> umap;
        while(right < s.length())
        {
          umap[s[right]]++;
            
        if(umap.size() == (right-left + 1)){
            ans = max(ans,right-left+1);
        }
        else if(umap.size() < (right-left+1)){
            while(umap.size() < (right-left+1)){
                umap[s[left]]--;
                
                if(umap[s[left]] == 0){
                    umap.erase(s[left]);
                }
                left++;
            }
        }
            right++;
        }
        return ans;
    }
};
