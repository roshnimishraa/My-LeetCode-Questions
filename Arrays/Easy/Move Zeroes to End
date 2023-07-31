Brute Force Approach : 
1. first make temporary array of non-zero elements and then add 0 
vector<int> moveZeros(int n, vector<int> a) {
    //temporary array:
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}

TC : O(2N ) 
SC: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
---------------------------------------------------------------------------------------------------------------------------------------


Better Approach : Partition the array in Non-Zero and Zero Element 
1. take pivot = 0
2. if arr[i] not equal to 0 then swap arr[i],arr[pivot] so that 0 element can be at end

TC : O(N) one for loop
SC : O(1) 

class Solution {  
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int pivot = 0;
        for(int i=0;i<n;i++){
          if(nums[i] !=0){
              swap(nums[i],nums[pivot]);
              pivot++;
          }
            }  
          }
};
