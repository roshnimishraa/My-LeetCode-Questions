1) Naive Approach
In this approach, we traverse the array and find the distinct elements, which are then copied to a new array. After all the distinct elements are copied to the new array, the elements from the new array are transferred back to the original array.

Time Complexity : O(n) 
Auxiliary Space : O(n)  // new array for storing distinct elements is required

--------------------------------------------------------------------------------------------------------------------------------------

2) Efficient Approach:
In this approach we compare the current element with the previous distinct element and check if the current element is a distinct element or not.

Time Complexity : O(n) 
Auxiliary Space : O(1)



 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res =1;
        int n = nums.size();
        
        
    for(int i=1;i<n;i++)
    {
        if(nums[i] != nums[res-1] )
                {
             nums[res]=nums[i];
               res++;
        }           
    }
        return res;
    }
};

