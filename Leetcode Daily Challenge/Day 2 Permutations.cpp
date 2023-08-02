Backtracking Questions patters 
All(Possible/Permutations/Combinations/Subsets) -> Backtracking is used

Approach : Backtracking & unordered_set(unique elements) & temp subarray & result array
1. index always start from 0
2.  if(temp.size() == n) store ans from temp and return -> corner case
3. For Distinct elemetnts in set 
if(s.find == s.end()) 
then add elements in temp and insert into set(for unique elements) 
4. Do recursive call from index+1 for remaining elements
5. Do backtrack pop elements from output
6. Also remove elements from set

Time Complexity : O(N! * N) 
N!-> permutations and O(N) for copy temp into result

class Solution {
    void helper(vector<int> &nums,int n, vector<int> &output,vector<vector<int>> &ans, unordered_set<int> &s){
        if(output.size() == n){
            ans.push_back(output);
            return;
        }
        for(int i=0;i<n;i++){
            if(s.find(nums[i]) == s.end()){
                output.push_back(nums[i]);
                s.insert(nums[i]);
                helper(nums,n,output,ans,s);
             
                   //exclude
                output.pop_back();
               s.erase(nums[i]);
            }      
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
     vector<int> output;
        int n=nums.size();
           unordered_set<int> s;
        helper(nums,n,output,ans,s);
        return ans;
    }
};
------------------------------------------------------------------------------------------------------------------------------------

Approach 2 : doing swaping between elements of an array
1. index = i (to avoid duplicacy) 
2. Corner Case ->index >= n from element in ans and return 
3. Do swap (nums[i],nums[index])
4. Do recursive call from index+1
5. Undo swap

class Solution {
    void helper(vector<int> &nums,int n,int index,vector<vector<int>> &ans)
    {
        // corner case  
        //index out of bound
        if(index>=n){
      ans.push_back(nums);
            return;
}
        for(int i=index;i<n;i++){
//swap
            swap(nums[i],nums[index]);
            helper(nums,n,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        int index=0;
        helper(nums,n,index,ans);
        return ans;
    }
};
