Approach : Using Sorting sort in decreasing order and return k-1 (because 0 based indexing)
  
TC : O(N LOG N) 

Eg.  nums[] = [ 3, 2, 1, 5, 6, 4] , k=2
output: 
 nums[] = [6,5,4,3,2,1]  (Sort in decreasing order) 
 return nums[k-1] = 5 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans =  nums[k-1];
        return ans;
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------
Approach : Priority Queue (Min-Heap) 
TC Best and Average Case : ( N * Log K) 
TC Worst Case : O(N * Log N) 

Logic : 
1. min heap.size() == k 
    if pq.size() > k then pq.pop() 
2. ans = pq.top()


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min-heap
      priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }

//      build min -heap
   for(int i=k;i<nums.size();i++){
 if(pq.top() < nums[i]) {
pq.pop();
   pq.push(nums[i]);
 }
   }
// lagest[i] = nums[k]
  return pq.top();
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------

Approach 3: QuickSelect(hoarse partition) 
TC : O(N) 
SC : O(1) 
