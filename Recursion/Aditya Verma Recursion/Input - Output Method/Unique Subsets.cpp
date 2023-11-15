class Solution
{
    void helper(int index,vector<int> &arr,vector<int> &output,
    vector<vector<int>> &ans)
    {
        if(index >= arr.size())
        {
            ans.push_back(output);
            return;
        }
        
        //include
        output.push_back(arr[index]);
helper(index+1,arr,output,ans);
output.pop_back();

 while(index+1 <arr.size() && arr[index]==arr[index+1])
    index++;
helper(index+1,arr,output,ans);
    }
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    sort(arr.begin(),arr.end());
    helper(index,arr,output,ans);
    sort(ans.begin(),ans.end());
    return ans;
    }
};
