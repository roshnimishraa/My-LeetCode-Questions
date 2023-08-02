Approach : stack & nextGr array
Corner Case : Elements of array are distinct

  1. pushing last element into st and initializing nextGr as -1
  2. checking array elements from n-2 if 
a) st.size() > 0 && st.top() <= arr[i] -> Agar stack ka top chhota arr[i] then use stack se pop kro 
b) if st.empty() == true -> nextGr = -1
  else nextGr[i] = st.top()
3. Push all the elements of array in stack at the greater element to right is left 

 Time Complexity : O(N)
 Auxiliary Space : O(N)

  class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
     stack<long long> st;
    st.push(arr[n-1]);
    vector<long long> nextGr(n);
 nextGr[n-1] = -1;
     for(int i=n-2;i>=0;i--){     
         while(st.size() > 0 && st.top() <= arr[i]){
             st.pop();
         }     
  if(st.size() == 0){
      nextGr[i] = -1;
  }
  else {
      nextGr[i] = st.top();
  }
  st.push(arr[i]);
     }
   
     return nextGr;
    }
};
