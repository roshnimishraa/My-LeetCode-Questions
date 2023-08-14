Problem Link(GFG) : https://practice.geeksforgeeks.org/problems/heap-sort/1

Approach : 
Left Child Formula : 2 * i + 1
Right Child Formula : 2 * i + 2
1. Heapify 
2. Build Heap  
3. Heap Sort

1. Build Max Heap : TC = O(N) 
2. while(size  > 1) : O(N)
  a)  swap (arr[0], arr[n-1]) remove arr[n-1] : O(1)
  b) decrease heap size 
  c) heapify root node(make max heap) O( log N) 

TC : O( N + log N) = TC : O (N log N) 
SC : O(log N) 

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
   	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
 
	if (largest != i) 
	{ 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest); 
	} 
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
//   converting given array into max heap 
  for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // max heap
       	buildHeap(arr,n); 

while(n > 0){
    swap(arr[0],arr[n-1]);
    n--;
    
    heapify(arr,n,0);
}

      
    }
};
