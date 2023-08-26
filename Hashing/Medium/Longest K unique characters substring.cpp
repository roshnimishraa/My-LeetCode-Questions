Follow up question : Longest K unique characters substring

--------------------------------------------------------------------------------------------------------------------------------------------------------------
Approach : Sliding Window variable size 

Better Approach : using set 
TC : O(2*N) 
SC : O(N) 

Approach : 
1. use unorder set and two pointers left and right initially set to 0 
2. if element unique insert into set and 
find length of substring = right - left + 1
   and update len 
3. update len when greater length found and return 
4. if duplicate char occur then erase from set and move left pointer 


  
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLen=0;
        int left=0;
        int right =0;
        
    while(right<s.length())
    {
        //if char already exists in set
     if(st.find(s[right]) == st.end() && right < s.length()){
         // if duplicate char not exists
        st.insert(s[right]);
        maxLen = max(maxLen,right-left+1);
        right++;
       
     }
     else {
   st.erase(s[left]); 
         left++; //move left 
     }
    }
    return maxLen;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Unordered_Map and Two Pointer left and right 
 In unordered_map store char , index 

 TC: O(N) -> map 
SC : O(N)  

Approach : 

1. If the current character is not in the map or its index is less than left, it means it is a new unique character.
2. We update the charMap with the character's index and update the maxLength if necessary.
3. If the character is repeating within the current substring, we move the left pointer to the next position after the last occurrence of the character.
4. We update the index of the current character in the charMap and continue the iteration.




------------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : vector array and two pointer 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     vector<int> umap(256,-1);
        int left=0;
        int right=0;
        int maxLen=0;
        int n = s.length();
 while(right < n)
 {
     //if character at right index exists or not 
if(umap[s[right]] != -1)
    //consider char till left to right pointer only
    left = max(umap[s[right]]+1,left);

    umap[s[right]] = right;

    maxLen = max(maxLen,right-left+1);
    right++;

 }
 return maxLen;
    }
};













  
