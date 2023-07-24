Brute Force Approach -> Sort + traverse from backback(n-2) to find SecondLargest 

Better Approach : Second Largest Element TC: O(N)+ O(N) = O(2N)
In this approach, we find the 2nd largest element in the array, by ignoring the largest element. It requires two traversals of the array
TC :  O(2N)
---------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : TC : O(N) 
In this approach, we find the 2nd largest element in the array, by a single traversal through the array. We maintain the record of the Largest and Second Largest element, which traversing through the array.

Time Complexity: O(n)

Corner Case : Array does not -ve number then SecondLargest will be INT_MIN
a0,a1,a2,...........ai-1, ai 
a0 to ai-1 = largest 

there can be 3 cases 
1. a[i] > a[largest] 
2. a[i] == a[largest] 
3. a[i] < a[largest] 
  a. SecondLargest = -1 : SecondLargest = i
  b. a[i] <= a[SecondLargest] : Ignore 
  c. a[i] > a[SecondLargest] : SecondLargest = i

//////////////////////////////CODE/////////////////////////////////////////////////////////////////////////////////////////////////////

int SecondLargest(vector<int> &arr,int n){
    int largest=arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]> largest){
             slargest = largest;
    largest=arr[i];
   
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int SecondSmallest(vector<int> &arr,int n){
    int smallest = arr[0];
    int sSmallest = INT_MAX;
    
    for(int i=1;i<n;i++){
        if(arr[i] < smallest){
           sSmallest = smallest;
           smallest = arr[i]; 
        }
        else if(arr[i] != smallest && arr[i] < sSmallest ){
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}


vector<int> getSecondOrderElements(int n, vector<int> a) {
   int sLargest = SecondLargest(a,n);
  int sSmallest = SecondSmallest(a,n);
    
return {sLargest,sSmallest};
    
}

