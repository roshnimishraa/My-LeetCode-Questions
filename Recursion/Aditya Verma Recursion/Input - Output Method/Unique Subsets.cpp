/*
Time Complexity  : O(2^N)
Space Complexity : O(N)
*/

class Solution {
public:
void helper(int index,vector<int> &nums,vector<int> &output,vector<vector<int>> &ans)
{
    if(index>= nums.size()){
        ans.push_back(output);
        return;
    }
    // take 
output.push_back(nums[index]);
helper(index+1,nums,output,ans);
output.pop_back();

// not take
// skip consecutive element(duplicates)
//eg. 1 2 2 3 
while(index+1 < nums.size() && nums[index] == nums[index+1])
{
index++;
}
helper(index+1,nums,output,ans);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> output;
    int index=0;
    sort(nums.begin(),nums.end());
    helper(index,nums,output,ans);
    sort(ans.begin(),ans.end());
    return ans; 
    }
};
