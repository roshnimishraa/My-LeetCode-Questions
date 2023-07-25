Problem Link : https://tinyurl.com/2oyfemdh

Approach : Select Minimum and Swaps
step 1 : 0 to n-1 
step 2 : 1 to n-1 
step 3 : 2 to n-1 
.
.
.

Generalisation searching is from n-2 to n-1 

TC: O(N2)
SC : O(1) 


void selectionSort(vector<int>&arr) {
    int n=arr.size();

    for(int i=0;i<=n-2;i++){
        int mini = i;
        
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[mini])
            mini = j;
        }
       // swap(arr[mini],arr[i]);
      int temp = arr[mini];
       arr[mini] = arr[i];
       arr[i] = temp;
    }
}
 
