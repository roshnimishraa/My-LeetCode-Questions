Time Complexity : O(N* logN)
Space Complexity : O(N) 

class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
          int temp[high-low+1];
        // left subarray size
        int left = low;
        int right = mid+1;
  int k =0;


while(left <= mid && right <= high)
{
    if(arr[left] <= arr[right])
    {
    temp[k++] = arr[left++];

    }
    else{
        temp[k++] = arr[right++];

    }
}
while(left <= mid){
         temp[k++] = arr[left++];

}
while(right <= high){
     temp[k++] = arr[right++];

}

// put array elements from temp array to original array
for(int i=low;i<=high;i++){
      arr[i] = temp[i-low]; // i - low to get correct order
}
  }
    public:
    void mergeSort(int arr[], int l, int r)
    {
      if(l<r){
          int mid = l + (r - l)/2;
         mergeSort(arr,l,mid);
         mergeSort(arr,mid+1,r);
         merge(arr,l,mid,r);
      }
    }
};
