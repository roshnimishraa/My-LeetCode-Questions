Problem Link : https://tinyurl.com/ypz3pawg

class Solution{
    public:
    bool solve(int index,vector<int> &arr,int sum,int k)
    {
   if(index == arr.size()){
      if(k == sum){
          return true;
      }
      else{
          return false;
      }
   }
   
   if(sum > k){
       return false;
   }
   sum += arr[index];   //take
 if(solve(index+1,arr,sum,k))
   return true;
   
//   not take 
sum -= arr[index];
if(solve(index+1,arr,sum,k))
return true;

return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
int index=0,sum=0;
return solve(index,arr,sum,k);
    }
};
