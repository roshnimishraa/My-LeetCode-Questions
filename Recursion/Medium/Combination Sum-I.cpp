Efficient Approach : Pick or not pick 
Time Complexity: O(2^t * k) where t is the target, k is the average length
Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
Why not (2^n) but (2^t) (where n is the size of an array)?
Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations

Approach: 
If you pick the element, again come back at the same index as multiple occurrences of the same element is possible so the target reduces to target – arr[index] (where target -arr[index]>=0)and also insert the current element into the data structure.

  class Solution {
    void helper(int index,int target,vector<int> &arr,vector<int> &output,
               vector<vector<int>> &ans)
    {
        int n=arr.size();
        //corner case 
        if(index ==n) {
            if(target == 0) {
                ans.push_back(output);
            }
            return;
        }
//     include 
        if(arr[index] <= target){
         output.push_back(arr[index]);

        helper(index,target-arr[index] ,arr,output,ans);
// The same number may be chosen from candidates an unlimited number of //times.       
//         while returning remove marked element in vector
            output.pop_back();
        }
        
//        exclude
    helper(index+1,target,arr,output,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<vector<int>> ans;
        vector<int> output;
        helper(index,target,candidates,output,ans);
        return ans;
    }
};
