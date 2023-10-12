Better Approach : Linear Search
TC : O(N) 
SC : O(1) 

class Solution {
public:
//     Linear Search 
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i=0;
    while(i<n-1 && arr[i] <arr[i+1])
    {
        i++;
    }
        //moutain index a[i]>a[i+1]
        return i;
    }
};

Efficient Approach : Binary Search 
TC : O(N LOG N) 
SC : O(1) 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low=0,high = n-1;
        while(low<high)
        {
  int mid = low+(high-low)/2;
        if(arr[mid] < arr[mid+1])
        {
            low = mid+1;
        }
            else{
                high = mid;
            }
        }
        //if l==r -> mountain index
        return low;
    }
};
              
