Approach : recursion and backtracking
// Explore every index at once && ignore duplicate arr[index] 
// sort the input before calculation 

Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.

class Solution {
    void helper(int index,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &output)
    {
        if(target == 0){
            ans.push_back(output);
            return;
        }
    for(int i=index;i<arr.size();i++){
//     base case 
            if(i > index && arr[i] == arr[i-1]) {
                  //skip 
                continue;
            }
                          
        if(arr[i] > target) {
            break;
        }
//         do not pick duplicates elements

        output.push_back(arr[i]);
      helper(i+1,target-arr[i],arr,ans,output);
        output.pop_back();
    }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
sort(candidates.begin(),candidates.end());
      helper(index,target,candidates,ans,output);
        return ans;
    }
};
