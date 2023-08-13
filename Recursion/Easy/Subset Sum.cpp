Naive Approach : generate power set 


Efficient Approach : Recursion with include and exclude
1. if index out of bound store sum and return 
2. while include sum+arr[i]
  

Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

  void helper(int index,vector<int> &arr,int sum,vector<int> &ans)
{
    //corner case
int n= arr.size();
if(index == n){
    ans.push_back(sum);
    return;
}

//  include 
helper(index+1,arr,sum+arr[index],ans);

// exclude 
helper(index+1,arr,sum,ans);
}

vector<int> subsetSum(vector<int> &num){
		vector<int> ans;
        int sum=0;
        int index=0;
 
    helper(index,num,sum,ans);
       sort(ans.begin(),ans.end());
    return ans;
}
