>> Also known as Find the Safe Position or Josephus Problem or Game of Death in a circle or Execution in Circle

TC : O(N) 
SC : O(1) 
  
class Solution {
public:
int helper(int n,int k){
    if(n == 1) {
        return 0;
    }
else{
  return  (helper(n-1,k)+k) % n;
}
}
    int findTheWinner(int n, int k) {
        return helper(n,k)+1; //+1 is for converting 0-based indexing to 1-based indexing
    }
};
