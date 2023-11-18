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
