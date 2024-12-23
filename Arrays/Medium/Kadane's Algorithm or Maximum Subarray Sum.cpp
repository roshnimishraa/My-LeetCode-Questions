Problem Link : https://leetcode.com/problems/maximum-subarray

Brute Force : 
Three Loop 
1. First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).

2. Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).

3. After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).

Time Complexity: O(N3), where N = size of the array.
SC : Space Complexity: O(1) as we are not using any extra space.

Better Solution : Using Two Loops 
1.  for i loop till n -> sum =0
2. for j=i loop till n -> sum += arr[j] we will add the current element to the sum of the previous subarray
   then find maxi = max(maxi,sum) 
Time Complexity: O(N2), where N = size of the array.
SC : O(1) 

class Solution {
public:
//     better solution 
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi = INT_MIN;
       
    for(int i =0;i<n;i++){
       int sum =0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            maxi = max(maxi,sum);
        }
}
        return maxi;
    }
};

Efficient Solution : Kadane's Algorithm or Maximum Subarray Sum 
This approach should not find max for -ve no.

Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop running N times.

Space Complexity: O(1) as we are not using any extra space.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum =0;
        
        for(auto it: nums){
            sum += it;
            
        maxi = max(sum,maxi);
            if(sum < 0 ){
                sum =0;
            }
        }
        return maxi;
    }
};



