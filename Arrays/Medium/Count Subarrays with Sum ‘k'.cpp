Approach : Two Pointer 
TC: O(N) -> unordered map 
SC :O(N)

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
// two pointer 
int left=0,right=0;
int n=a.size();
long long sum =0;
vector<vector<int>> ans;
while(right < n){
    sum += a[right];
   while(left < right && sum > k){
        sum -= a[left];
        left++;
        
    }
    if(sum == k){
        vector<int> temp;
        for(int j=left;j<=right;j++){
            temp.push_back(a[j]);
        }
      ans.push_back(temp);
    }
    right++;
  
}
return ans;
}
