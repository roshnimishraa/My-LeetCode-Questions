Find Peak element : arr[i-1] < arr[i] > arr[i+1] 
  if peak element does not exist then return n-1 element

Approach : Linear Search 
class Solution {
public:
//     linear appraoch
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
            {
             return i;
            }
        }
        return n-1;
    }
};

Approach 2 : Binary Search 
TC : O(LOG N) 
SC : O(1) 
  
 if arr[mid] < arr[high] then low = mid + 1
if arr[mid] < arr[low] then high = mid-1

Corner Case :
if the array is in decreasing order = a[0] is the peak ele
if the array is in increasing order = a[n-1] is the peak ele

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
    if(n == 1) {
        return 0;
    }
        
if(nums[0] > nums[1]) {
    return 0;
}
if(nums[n-1] > nums[n-2])
{
    return n-1;
}
int low = 1,high = n-2;
    while(low<=high)
    {
        int mid = low +(high-low)/2;
if(nums[mid-1] < nums[mid] && nums[mid]> nums[mid+1])
{
    return mid;
}
        else if(nums[mid] > nums[mid-1])
{
    low = mid+1;
}
else 
{
 high=mid-1;
}
    }
        return -1;
    }
};
