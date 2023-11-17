Naive Approach : using Set 
Time Complexity : O(2^n*( klog(x) )).2^n
Space Complexity : O(2^n * k)

  
class Solution{
public:
    
    void solve(vector<int>&nums, int i, vector<int>ds, set<vector<int>>&st) 
    {
        if(i == nums.size()) 
        {
            sort(ds.begin(), ds.end());
            st.insert(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        solve(nums, i + 1, ds, st);
        ds.pop_back();
        solve(nums, i + 1, ds, st);
    }
    
    vector<vector<int>>subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>ds;
        
        solve(nums, 0, ds, st);
        for(auto &v : st) 
            ans.push_back(v);
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach 
  
Time Complexity : O(k * 2^n)
Space Complexity : O(2^n * k)
  
class Solution {
public:
void helper(int index,vector<int> &nums,vector<int> &output,vector<vector<int>> &ans){
    ans.push_back(output);

for(int i=index;i<nums.size();i++)
{
    if(i!=index && nums[i] == nums[i-1])
    continue;
    output.push_back(nums[i]);
helper(i+1,nums,output,ans);
output.pop_back();
}

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
    vector<int> output;
sort(nums.begin(),nums.end());
helper(0,nums,output,ans);
return ans;
    }
};
