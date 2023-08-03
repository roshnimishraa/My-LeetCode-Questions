Approach : Backtracking (first include and then backtrack (exclude)
TC : nCk

eg. n=5 k=2
(1,2,3,4,5) k=2 I can choose two elements in an array order doesn't matter
print comibinations of arr

[(1,2),(2,3),(4,5),(1,3),(1,4),(1,5),(2,4),(2,5),(3,4),(3,5)]

class Solution {
    void helper(int index,int n,int k,vector<int> &output,vector<vector<int>> &ans)
    {
        //corner case 
        if(k==0){
           ans.push_back(output);
       return;
        }
        if(index>n){
            return;
        }
        //include
        output.push_back(index);
        helper(index+1,n,k-1,output,ans);
        
        //exclude
        output.pop_back();
    helper(index+1,n,k,output,ans);
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        
      int index =1;
        helper(index,n,k,output,ans);
        
        return ans;
    }
};
----------------------------------------------------------------------------------------------------------------------------------

Approach 2 : using For loop

class Solution {
    void helper(int index,int n,int k,vector<int> &output,vector<vector<int>> &ans)
    {
        if(k==0){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<=n;i++){
            output.push_back(i);
            helper(i+1,n,k-1,output,ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =1;
        helper(index,n,k,output,ans);
        return ans;
    }
};
