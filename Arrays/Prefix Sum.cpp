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
----------------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : Pre Computation 
TC : O(1) 
SC : O(N) 
  
Eg.  arr[] = [2, 8, 3, 9, 6, 5, 4]
    Queries : getSum(0,2) 
            getSum(1,3) 
            getSum(2,6) 
1. PreCompute Prefix Sum Array 
pSum = [2, 10, 13, 22, 28, 33, 37]

pSum[i] = summison of arr[i] from 0 to i

2. getSum(l,r) 
a) pSum[r] if l==0

b) pSum[r] - pSum[l-1] otherwise 

Dry Run 
 arr[] = [2, 8, 3, 9, 6, 5, 4]

pSum = [2, 10, 13, 22, 28, 33, 37]
1. getSum(0,2) l==0 
  pSum[2] 
Output = 13

2. getSum(1,3) 
  pSum[3] - pSum[1-1] = pSum[3] - pSum[0] 
=  22 - 2 = 20

3. getSum(2,6) 
    pSum[6] - pSum[2] = 37 - 10
output = 27 

**********************************************Source Code*************************************************************************************************

1. preprocessing 

  int ps[n] 
  ps[0] = arr[0] 
  for(int i=0;i<n;i++) 
  ps[i] = ps[i-1] + ps[i] 

2. getSum 
  int getSum(l,r) {
if(l == 0) 
return ps[r] 
else 
return ps[r] - ps[l-1] 
}
