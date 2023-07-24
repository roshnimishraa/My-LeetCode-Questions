class Solution{
    public:
    
    void reverse(int arr[],int low,int high){
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        d = d % n; // Adjust d to handle cases where d > n
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    }
};
