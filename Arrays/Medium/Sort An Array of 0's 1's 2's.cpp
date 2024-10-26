Brute Force : Merge Sort 
TC : O(NlogN)
SC : O(N)

Better Solution 
1. Take ZeroCount, OneCount, TwoCount 
2. three loop for sort the ZeroCount, OneCount, TwoCount

TC : O(2N) 
SC : O(1) 
--------------------------------------------------------------------------------------------------------------------------------------
Optimal Solution : Dutch National Flag Algorithm 
TC : O(N) 
SC : O(1) 

0->Red              
1->White 
2->Blue 

3 Rule -> 
0 to low-1 -> 0 
low to mid-1 -> 1 
high+1 to n-1 -> 2

****Using Three Pointer(low,mid,high)****
Check Value of arr[mid] -
1. if 0 -> swap(arr[low],arr[mid])  low++ , mid++
2. if 1 -> mid++
3. if 2 -> swap(arr[mid],arr[high])    high--

////////////////////////       Code        ////////////////////////    Code     ///////////////    Code        ///////////////////   
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
            low++;
                mid++;
            }
            else if(nums[mid] ==1){
                mid++;
            }
            else{
                //nums[mid] == 2
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
