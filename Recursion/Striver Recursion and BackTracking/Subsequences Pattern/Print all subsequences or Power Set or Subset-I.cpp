Approach : Recursion + Backtracking => Take and Not take 

TC : O(N * 2^N) 
SC : O(N) 

class Solution {
public:
void helper(int index,vector<int> &nums,vector<int> &output,vector<vector<int>> &ans){
    // base case 
    if(index>= nums.size()){
        ans.push_back(output);
    return;
    }
// include
output.push_back(nums[index]);
helper(index+1,nums,output,ans);
output.pop_back();

// exclude
helper(index+1,nums,output,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> output;
    helper(0,nums,output,ans);
    return ans;   
    }
};
