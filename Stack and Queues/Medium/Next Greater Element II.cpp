Constraints 
1. Duplicates elements 
2. Circular array 

eg. a[] = [1,2,1] 
  output[] = [2,-1,2]

TC : O(2N+2N) = O(N) 
SC : O(N)

Logic :
1. make copy of array so that it points to 0 to n do 
i%n 
for arr[2,10,12,1,11] 2,10,12,1,11 (0 to 9) 
  i%n = 5 % 5 = 0th index
        6 % 5 = 1th index 
        7 % 5 = 2th index 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        st.push(nums[n-1]);
        vector<int> nextGr(n);
        nextGr[n-1] = -1;
        
   for(int i=2*n-1;i>=0;i--)
    {
while(!st.empty() && st.top() <= nums[i%n]){
    st.pop();
}
      
       if(i<n){
             if(st.empty()){
            nextGr[i] = -1;
        }
        else{
            nextGr[i] = st.top();
        }
       }
        st.push(nums[i%n]);
    }
        return nextGr;
    }
};
