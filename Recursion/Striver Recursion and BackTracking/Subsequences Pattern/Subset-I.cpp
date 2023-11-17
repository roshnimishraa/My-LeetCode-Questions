Naive Approach : Using Power Set 

TC : O(N * 2^N) 
SC : O(1) 
    class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		vector<string> ans;
		int n = s.length();
		for(int num=0; num<2^n-1;num++){
		   string str = ""; 
		   for(int j = 0; j<n-1;j++){
		       if(num & (1<<j)){
		           str += s[j];
		       }
		   }
		   		ans.push_back(str);
		}

		return ans;
		}
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------
    
Efficient Approach : Using Recursion 

TC : O(2^N + 2^Nlog(2^N)) log n for sorting 
SC : O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
class Solution
{
public:
void helper(int index,int sum,vector<int> &arr,vector<int> &ans)
{
    //base case when index out of bound then, ans is found 
    if(index == arr.size()){
        ans.push_back(sum);
        return;
    }
    // include
    helper(index+1,sum+arr[index],arr,ans);
    
    // exclude
    helper(index+1,sum,arr,ans);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0,index=0;
        vector<int> ans;
        helper(index,sum,arr,ans);
    sort(arr.begin(),arr.end());
    return ans;
    }
};
