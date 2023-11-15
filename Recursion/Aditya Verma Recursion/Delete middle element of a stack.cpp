Approach : Recursion 
  
class Solution
{
    void helper(stack<int> &st,int count,int size){
  if(count == size/2){
     st.pop();
     return;
  }
//   if count != mid pop top of st until count == mid
int num = st.top();
st.pop();

// recursive call
helper(st,count+1,size);

// now mid ele is deleted insert st top ele which is popped
st.push(num);

    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
int count=0;
helper(s,count,sizeOfStack);
    }
};
