Brute force Approach : Using one for loop
TC : O(N) 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
  vector<int>ans;
        int first = -1, last = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                    last = i;
                }
                else
                    last = i;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};

Better Approach : 
lower Bound & upper Bound -> TC : 2* O(log N) 

for Upper Bounder = i-1 = ( ub - 1) 

---------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Binary Search 
TC : O(log N) 

Logic : 
for First Occurence 
 if mid == target definately for first occurence of element I  have search to in left;

Fro Last Occurence 
 if mid == target definately for last occurence of element I have to search in right;
class Solution {
    int firstOcc(vector<int> &arr,int target)
    {
int n = arr.size();
        int low = 0;
        int high = n-1;
     int first=-1;
        while(low <= high)
        {
       int mid = (low + high)/2;
            
        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }
    else if(arr[mid] > target)
    {
     high = mid-1;
    }
  else {
      //arr[mid] < target
      low = mid + 1;
  }
        }
      return first;
        
    }
    int lastOcc(vector<int> &arr,int target)
    {
int last =-1;
        int n =arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
        
        if(arr[mid] == target){
            last = mid;
            low = mid + 1;
            
        }
        else if(arr[mid] > target){
            high = mid -1;
        }
            else {
                //arr[mid] < target
        low = mid + 1;
            }
        }
        return last ;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = firstOcc(nums,target);
        int l = lastOcc(nums,target);
        return {f,l};
    }
};
