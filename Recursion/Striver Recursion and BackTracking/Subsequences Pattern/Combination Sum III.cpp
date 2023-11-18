Eg.1 
Input:
K = 3
N = 7
Output: { {1, 2, 4} }
Explanation: 
1+ 2+ 4 = 7

Eg2.
Input:
K = 3
N = 9
Output: { {1, 2, 6}, {1, 3, 5}, {2, 3, 4} }
Explanation: 
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9


Time Complexity: O(2^N)
Space Complexity: O(K)

  class Solution {
public:
// k is number of elements 
// n is sum or target 
void helper(int index,int k,int n,int sumTillNow,vector<int> &output,vector<vector<int>> &ans)
{
// base case 
if(sumTillNow == n){
    if(k==0){
        ans.push_back(output);
    }
    return;
}


if(sumTillNow > n){
    return;
}
if(index == 10){
    return;
}
// take 
sumTillNow += index;
output.push_back(index);
// recursive call for i+1 numbers
helper(index+1,k-1,n,sumTillNow,output,ans);
// backtrack
sumTillNow -= index;
output.pop_back();

//not take
helper(index+1,k,n,sumTillNow,output,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> output;
    int sum =0;
// index = 1 because number is given from 1 to 9
helper(1,k,n,sum,output,ans);
return ans;
    }
};
