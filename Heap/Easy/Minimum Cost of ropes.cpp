Approach : Min Heap(Priority queue) 

Eg. [4, 3, 2, 6]
output 
1. Min Heap 
  [2, 3, 4, 6]
2. add min adjacent element and sum to their element with other min element 
 [ 5, 4, 6]  = (2 + 3) 
3. [9, 6]  = (5 + 4) 
4 [15]  = ( 6+9) 
 
Total Cost = 5 + 9 + 15 = 29 

Time Complexity : O(nlogn)
Auxilliary Space : O(n)

  class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
       priority_queue<long long,vector<long long>,greater<long long>> pq;
       
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
      long long sum=0;
       while(pq.size() >1 ){
           long long sum1=pq.top();
           pq.pop();
         long long sum2 = pq.top();
           pq.pop();
           
        sum += sum1+sum2;
           pq.push(sum1+sum2);
       }
       return sum;
    }
};
