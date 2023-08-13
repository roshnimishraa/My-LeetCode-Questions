Approach : Take and Skip 

TC : O(N * 2^N) 
SC : O(N) 

class Solution {
    
    void helper(int index,vector<int> &output,vector<int>& nums,vector<vector<int>> &ans)
    {
        int n=nums.size();
 if(index >= n){
     ans.push_back(output);
     return;
 }
//    include
        output.push_back(nums[index]);
helper(index+1,output,nums,ans);
    
//       exclude
        output.pop_back();
helper(index+1,output,nums,ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
    helper(index,output,nums,ans);
        return ans;
    }
};
