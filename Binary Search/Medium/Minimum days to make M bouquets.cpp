Naive Approach(Brute force): 
The extremely naive approach is to check all possible answers from min(arr[]) to max(arr[]). The minimum number for which possible() returns true, is our answer.
Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Space Complexity: O(1) as we are not using any extra space to solve this problem.

Algorithm:
1.	If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
2.	We will run a loop(say i) from min(arr[]) to max(arr[]) to check all possible answers.
3.	Next, we will pass each potential answer, represented by the variable ‘i’ (which corresponds to a specific day), to the ‘possible()’ function. If the function returns true, indicating that we can create ‘m’ bouquets, we will return the value of ‘i’.
4.	Finally, if we are outside the loop, we can conclude that is impossible to make m bouquets. So, we will return -1.


Eg. Bloom Day = [7 7 7 7 13 11 12 7]    m=2 , k=3
Take minimum integer from which day no. of bouquets(flowers bloom) is possible
11th day =      Y Y Y Y N Y N Y 
11th day is not possible that means 1-11 -> cannot be the ans
12th day =      Y Y Y Y N Y Y Y 
12th day is possible
13th day  =      Y Y Y Y Y Y Y Y
13th is possible
We have to return minimum int -> 12th day is the answer

Corner Case 
[ 1 10 3 10 2] m=3 , k=2
 Since N=5 
m*k > N -> Not possible to make bouquets return -1 (This means we have insufficient flowers)
------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : Binary Search 

Time Complexity: O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Reason: We are applying binary search on our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer ‘mid’, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.

Eg. Bloom Day = [7 7 7 7 13 11 12 7]
ans is b/w 7-13
find mid -> if mid is possible ans then high = mid - 1(find min day) 
continue till low <= high 


class Solution {
    int possible(vector<int> &arr,int day,int m,int k){
        int count=0;
        int n=arr.size();
        int noOfBouquet = 0;
      //day = mid
        for(int i=0;i<n;i++){
            if(arr[i] <= day){
                count++;
            }
            else{
               noOfBouquet += (count/k);
                count = 0; 
            }
        }
        //No. of bouquets in any array can be formed 
       noOfBouquet += (count/k);
        return noOfBouquet >=m; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        //corner case m*k > n 
        long long val=1LL*m*k;
        if(val > n){
            return -1;
        }
    //find min & max in an array 
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            
                 mini = min(bloomDay[i],mini);
                maxi = max(bloomDay[i],maxi);
         
        }
        
//   apply binary search 
        int low = mini,  high = maxi;
        int ans =-1;
    while(low<= high){
        int mid= low + (high-low)/2;
        if(possible(bloomDay,mid,m,k))
        {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        }
        return low;
    }
};
