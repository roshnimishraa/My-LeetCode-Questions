Method 1 : Sorting 
  TC : O( N LOG N)
    
  class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
       //code here
        sort(arr, arr+(r+1));
        return arr[k-1];
    }
};

Method 2 : Using max heap

   int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq; // Max heap
        
        for (int i = 0; i<=r; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
