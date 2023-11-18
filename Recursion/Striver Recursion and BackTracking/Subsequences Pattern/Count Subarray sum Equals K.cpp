Topic : Arrays -> Prefix sum
  
Brute Force : Using Three Nested loops 
TC : O(N^3) 
  
class Solution{
    public:
    int findSubArraySum(int arr[], int n, int target)
    {
      int count=0;
      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              int sum=0;
             for(int k=i;k<=j;k++){
                 sum += arr[k];
                 
       }
          if(sum == target){
            count++;
        }
          }
        
             
      }
      return count;
    }
};


Better Approach : Using two loops 
TC : O(N^2) 

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int target)
    {
      int count=0;
      for(int i=0;i<n;i++){
           int sum=0;
          for(int j=i;j<n;j++){
               sum += arr[j];
         if(sum == target){
            count++;  
   }
 }
   }
      return count;
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Optimal Approach using Prefix Sum

Question: Why do we need to set the value of 0?
Let’s understand this using an example. Assume the given array is [3, -3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix sum as 3, and k is also 3. So, the prefix sum of the remove-part should be x-k = 3-3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 for the key 0 and we will add 0 to our answer. This will mean that we have not found any subarray with sum 3 till now. But this should not be the case as index 0 itself is a subarray with sum k i.e. 3.
So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.

Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, 
  the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
   int count =0,prefixSum=0;
   unordered_map<int,int> mp;
   mp[0] = 1;
   for(int i=0;i<n;i++){
       prefixSum += arr[i];
       
       int remove = prefixSum - k;
       count += mp[remove];
       mp[prefixSum]+=1;
   }
   return count;
    }
};
