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
