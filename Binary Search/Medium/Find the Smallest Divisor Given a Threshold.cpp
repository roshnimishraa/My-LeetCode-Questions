Naive Approach : 
check all divisors from 1 to n
•	We will run a loop(say d) from 1 to max(arr[]) to check all possible divisors.
•	To calculate the result, we will iterate over the given array using a loop. Within this loop, we will divide each element in the array by the current divisor, d, and sum up the obtained ceiling values.
•	Inside the outer loop, If result <= threshold: We will return d as our answer.
•	Finally, if we are outside the nested loops, we will return -1.

Efficient Approach : BS on Answer
possibleanswer(arr,divisor)
 sum = sum + ceil((double)(arr[i]) /(double)(div));

1. Range 1 to high 
2. if mid is possible answer then high=mid-1 check for smallest 

eg. arr[] = [1, 2, 5, 9]
1.  mid = 5 , it is the possible answer high = mid-1
2.  mid=2 , it is not possible answer low = mid+1
3.  mid=3, it is possible answer high = mid-1
4.  high crosses low stop 

TC: O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array.
SC : O(1) 

class Solution {
    int sumByD(vector<int> &arr,int div)
    {
        int sum =0;
        int n=arr.size();
        for(int i=0;i<n;i++)
   {
     sum = sum + ceil((double)(arr[i]) /(double)(div));
     }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
      int high = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > high) {
            high = nums[i];
        }
    }
        
  while(low <= high)
        {
     int mid = (low + high)/2;
            if(sumByD(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
