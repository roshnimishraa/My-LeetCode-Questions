Approach: Pushes the maximum to the last by adjacent swaps (Opposite of Selection Sort) 

Pass 1: 0 to n-1 
Pass 2: 0 to n-2 
Pass 3: 0 to n-3 
Pass n : 0 to 1

First loop (i) -> n-1 to >=0 
Second Inner Loop (j) -> 0 to <=i-1 

TC : O(N2) -> worst & average case for best case O(n) 
SC : O(1) 


void bubbleSort(int arr[], int n) 
{  
   for(int i=n-1;i>=0 ; i--){

       for(int j=0; j<=i-1;j++){
           if(arr[j] > arr[j+1])
           {
       //    swap(arr[j],arr[j+1]);
       int temp = arr[j+1];
       arr[j+1]= arr[j];
       arr[j] = temp;
           }
       }
   }
}


