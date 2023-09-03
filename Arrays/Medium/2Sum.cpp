Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

Appoach 1 : Using Two For loops  TC : O(N)^2

Approach 2 : Using Map TC : O(N )  -> Traversing only once the elements 

Eg. arr[] = [2, 6, 5, 8, 1]  target=14 
    5 + rem_num = 14 
  rem_num = 14-5 = 9 if 9 is present return rem_num index, i 
  if not return empty array 

So, rem_num = target-nums[i] 

check for 8 search 6 in map and found at index 1 
return [1,3] 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> umap;
        int n= nums.size();
        int rem_num =0;
    for(int i=0;i<n;i++)
    {
rem_num = target-nums[i];
//if exists
if(umap.find(rem_num) != umap.end()){
    return {umap[rem_num],i};
}
else{
    umap.insert({nums[i],i});
}

    }

return {0,0};
    }
};

Approach 3 : Two Pointer
TC : O(N) + sort O (N LOGN ) ~ O(N) 
SC O(1) 

Algo 
1. Sort the array 
2. take left and right pointer where 
left =0 and right = n-1
now if arr[left]+arr[right] < target then left++
else if (arr[left]+arr[right] > target then 
    right--
else if arr[left] + arr[right] == target return "YES"
else 
    return "NO"
    


string read(int n, vector<int> book, int target)
{
 int left=0;
 int right = n-1;
 sort(book.begin(),book.end());
 
 while(left<=right){
    int check_num = book[left]+book[right];
    if(check_num < target){
        left++;
    }
    else if(check_num> target) {
        right--;
    }
    else if(check_num == target){
        return "YES";
    }
   
 }
 return "NO";
}
