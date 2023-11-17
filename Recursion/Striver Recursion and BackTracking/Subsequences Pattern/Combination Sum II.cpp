Given : 
1. No Duplicates number output / subset
2. Each number can only be used only once
3. Return output in Sorted order 

Naive Approach : 
- Time complexity: O(k * log(d) * 2^n)
where k is the average length of ds, d is the average length of set
log(d) because we are using set here

- Space complexity:  O(k x t)
If ‘k’ is the avg length of every combination and ‘t’ is the no. of combinations

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

------------------------------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : Subsequences based selection 

/*TC : O(2^n * k) where n = number of subsequences 
                 and k = average length of combinations
SC : O(k*x) k = average length  x = no. of combinations */
