Efficient Approach : Priority Queue (Min Heap) 
TC : O (N * LOG K) 
SC : O(n)

vector <int> nearlySorted(int arr[], int num, int K){
        priority_queue<int,vector<int>,greater<int>>pq;
 vector<int>ans;
    for(int i=0;i<num;i++){
        pq.push(arr[i]);
    
    if(pq.size() > K){
        ans.push_back(pq.top());
    
        pq.pop();
    }
    
    }
    //remaining elements after pop
    while(pq.size() > 0){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
    }



---------------------------------------------------------------------------------------------------------------------------------------------------------------
Brute Approach : ( TLE )
The idea is to traverse the array from left to right and for every element at ith index, look for minimum element from index i to index i+k and swap ith index element with minimum element found to get sorted element at ith index as it mentioned that sorted element is at most a distance of k.
  TC : O(N * K) 
SC : O(N) 

  vector <int> nearlySorted(int arr[], int n, int k){
vector<int> ans;
for(int i=0;i<n;i++){
    int mini = arr[i];
    int miniIndex = i;
    for(int j=i;j<=min(i+k,n-1);j++){
        if(arr[j]<mini){
            mini = arr[j];
            miniIndex =j;
        }
    }
    swap(arr[i],arr[miniIndex]);
    ans.push_back(mini);
}
return ans;
