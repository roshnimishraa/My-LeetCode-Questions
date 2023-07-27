Brute Force Approach 
Approach(Using linear search): 
We can guarantee that our answer will lie between the range from 1 to m
func(x, n) = m  returns the value of x raised to the power n i.e. x^n.

Time Complexity: O(M), M = the given number.
Reason: Since we are using linear search, we traverse the entire answer space.

Space Complexity: O(1) as we are not using any extra space. 


// Power exponential method:
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}

int NthRoot(int n, int m) {
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = func(i, n);
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}

---------------------------------------------------------------------------------------------------------------------------

Efficient Solution : Binary Search 
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).



// int func(int mid,int n){
//     long long ans = 0;
//     while(n>0){
//         if(n % 2== 0){
//             ans = mid * mid;
//             n = (n/2);
//         }
//         else{
//             // n%2 == 1
//             ans = ans *mid;
//             n = n-1;

//         }
//     }
//     //mid ^ n  // this might give overflow
//     return ans;
// }

//  return 1 if == m
//  return 0 if < m 
//  retur 2 if > m
int func(int mid, int n, int m) {

    long long ans = 1;

    for (int i = 1; i <= n; i++) {

        ans = ans * mid;

        if (ans > m) 

        return 2;

    }

    if (ans == m) 

    return 1;

    return 0;

}

int NthRoot(int n, int m) {
  int low = 1;
  int high = m;
  while(low <= high){
     int mid =low + (high - low)/2;
      int midN = func(mid,n,m);

      if(midN == 1){
         return mid;
      } 
   else if (midN == 0) low = mid + 1;
   else 
   high = mid -1;

  }
      return -1;
  }

