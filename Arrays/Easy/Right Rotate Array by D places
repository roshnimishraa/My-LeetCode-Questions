Method 1 
3 steps : For Right Rotation of D places 
1. Reverse the whole array -> 0 to n-1
2. Reverse first K elements -> 0 to k-1
3. Reverse n-k elements -> k to n-1
class Solution {
public:
    void reverse(vector<int> &nums,int low, int high){
        while(low<high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n; // for k>n
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};

--------------------------------------------------------------------------------------------------------------------------------------

Method 2 
3 step 
1. create a vector temp 
2. find Rotated position -> cycle way me K position se shift kro 
 arr[(i+k) % n] = arr[i]
3. copy temp into arr vector 
 nums = temp 

TC : O(N) 
SC : O(1) 


 class Solution {
public:
    void rotate(vector<int>& nums, int k) {
//  % -> it gives no. from (0 to n-1)
   
        int n = nums.size();
        
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k) % n] = nums[i];
            
        }
//    copy temp into nums vector 
        nums = temp;
    }
};
