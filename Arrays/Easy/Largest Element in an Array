Naive two traversal technique. TC: O(N)^2

Efficient approach 
a0, a1,a2, a3,..........ai-1, ai

let a0 to ai-1 -> alargest 

There can be 2 cases 
ai <= alargest  -> ignore 
ai > alargest    -> update largest = i

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
  
   int largest =arr[0];
   for(int i=1;i<n;i++){
     if (arr[i] > largest) {
       largest = arr[i];
     }
   }
       return largest ;
  
}

TC : O(N)
SC : O(1) 
