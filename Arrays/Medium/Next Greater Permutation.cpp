Apporach : 
1. Find the break-point, i: 
  Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].

For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). 
Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.

Algo 
1. Find breaking point arr[i] < arr[i+1] seach from last (n-2) store index as idx1 break
2. Corner case breaking point not exist that's mean it is in descending order reverse the array if idx1<0 
Eg. 5 4 3 2 1 (Last permutation) 
  reverse : 1 2 3 4 5 
3. After finding idx1 search for closet greater value from last store index as idx2 break 
4. now swap idx1 and idx2 
5. and sort after idx1 sort(arr.begin()+idx1,arr.end()) 


Time Complexity: O(3N), where N = size of the given array
Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, 
where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).
Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1,idx2;
    int n=nums.size();
if(n==1) return;

// traverse from last(n-2) and search for 
// breaking point if found store index as idx1 
for(int i=n-2;i>=0;i--)
{
    if(nums[i]<nums[i+1])
    {
        idx1 = i;
        break;
    }
}
// corner case nums[i]>nums[i+1] breaking point 
// not found (descending order and largest ele)
// reverse it 
if(idx1 < 0){
    reverse(nums.begin(),nums.end());

}
else{
for(int i=n-1;i>=0;i--)
{
    idx2=0;
    if(nums[i]> nums[idx1]){
        idx2=i;
        break;
    }

}
    swap(nums[idx1],nums[idx2]);
            
            sort(nums.begin()+idx1+1,nums.end());
}


    }
};
