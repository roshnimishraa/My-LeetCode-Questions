Approach : Sliding Window
1. Variable Size window size
2. given K number of zeroes can be flip 

if a subarray there can be atmost k size 0 
return max(ans,j-i+1)

TC : O(N) 
SC : O(1) 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans = INT_MIN;
        int zeroCount=0;
        int n=nums.size();
        while(j<n)
        {
      if(nums[j] == 0){
          zeroCount++;
    
      }
            while(zeroCount > k){
               if(nums[i] == 0){
                   zeroCount--;
               }
                i++;
            }
            ans = max(ans,j-i+1);
         j++;
        }
      return ans;
    
    }
};
