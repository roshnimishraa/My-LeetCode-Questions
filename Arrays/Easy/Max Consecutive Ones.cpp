Naive Approach :
TC : O(N)^2
SC : O(1)
In this approach, we use two loops and traverse the array from start to end. At each element, we check if it is 1 or 0. If the element is 1, we increment the count variable and count the number of 1s along with it if any. After each completion of the inner loop, we find the maximum between the current count and the previous count.

Efficient Approach 
An efficient solution is to traverse the array from left to right. If we see a 1, we increment the count and compare it with the maximum so far. If we see a 0, we reset the count to 0.

Time Complexity : O(n) 
Auxiliary Space : O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        int curr =0;
        for(int i=0;i<n;i++){
            
          
            if(nums[i] == 0){
                curr =0;
            }
            else{
                curr++;
               res = max(res,curr);
            }
             
        }
        return res;
    }
};
