Time Complexity : O(N * LOG N) 
Space Complexity : O(1)

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
 if(low<high){
     int pivdx =partition(arr,low,high);
     quickSort(arr,low,pivdx-1);
     quickSort(arr,pivdx+1,high);
 
 }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
      int pivot = arr[high];
       int i=low-1;
       for(int j=low;j<high;j++){
        //   smaller window element
           if(arr[j]<pivot)
       {
                i++;
         swap(arr[i],arr[j]);
       }
    
       }
    //   placing pivot before first greater element
       swap(arr[i+1],arr[high]);
    //   return pivot index
       return i+1;
    }
};
