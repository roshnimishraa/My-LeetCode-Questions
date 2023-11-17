Naive Approach : Using Power Set 

TC : O(N * 2^N) 
SC : O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

void solve(vector<int>& nums,int index,int sum,vector<int> &ans)
{
    if(index==nums.size()){
        ans.push_back(sum);
        return;
    }
//take 
solve(nums,index+1,sum+nums[index],ans);

//not take 
solve(nums,index+1,sum,ans);
}
 
vector<int> subsetSum(vector<int> &num){

      vector<int> ans;
      int index =0;
      int sum =0;
  solve(num,index,sum,ans);
    sort(ans.begin(),ans.end());
    return ans; 
}
