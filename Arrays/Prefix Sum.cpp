Eg. arr[] = [2, 8, 3, 9, 6, 5, 4]
  Queries : getSum(0,2) 
            getSum(1,3) 
            getSum(2,6) 
  Output : 13 20 27

Naive Approach : traversing the whole subarray 
TC : O(N) or theta(r-l+1)
SC: O(1) 

getSum(int l,int r) {
  int res=0;
  for(int i=0;i<=r;i++)
    res += arr[i];
  return res;
}

Efficient Approach : Pre Computation 
TC : O(1) 
SC : O(1) 
  
Eg.  arr[] = [2, 8, 3, 9, 6, 5, 4]
1. PreCompute Prefix Sum Array 
pSum = [2, 10, 13, 22, 28, 33, 37]

pSum[i] = summison of arr[i] from 0 to i

2. getSum(l,r) 
a) #pSum[r] if l==0
b) 
