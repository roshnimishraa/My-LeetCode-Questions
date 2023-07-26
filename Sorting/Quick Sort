Quick Sort (Divide and Conquer technique)
TC : O(n log n )
SC : O(1) 

Step for Quick Sort 
1. Pick a pivot and place it in its correct place in the sorted array.
2. Smaller on the left and Larger on the right 


int partitionArray(int input[], int start, int end) {
      int pivot = input[start];
      int i=start;
      int j= end;
      while(i<j){
          while(input[i] <= pivot && i <= end-1){
              i++;
          }
          while(input[j] > pivot && j >= start + 1){
              j--;
          }
          if(i < j){
              swap(input[i], input[j]);
          }
      }
      swap(input[start], input[j]);
      return j;
}

void quickSort(int input[], int start, int end) 
{
    if(start < end){
int pivotIndex = partitionArray(input,start,end);
    quickSort(input,start,pivotIndex-1);
    quickSort(input,pivotIndex+1,end);
    }        
}
