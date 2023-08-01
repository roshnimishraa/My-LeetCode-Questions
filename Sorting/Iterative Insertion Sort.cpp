Approach : Takes an element and places it in its correct position
i = 0 to n-1 
j = i 
and swap for j> 0 &&  arr[j-1] > arr[j] and do j-- 

TC : Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Best Case : O(N) 
SC : O(1)


void insertionSort(int arr[], int n)
{
    for(int i=0;i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j])
        {
          int temp = arr[j-1];
          arr[j-1]=arr[j];
          arr[j] = temp;

          j--; //check till 0th index 
        }
    }
}
