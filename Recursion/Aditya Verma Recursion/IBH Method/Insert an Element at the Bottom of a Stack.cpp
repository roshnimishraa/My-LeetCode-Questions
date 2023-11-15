class Solution{
public:
void helper(stack<int> &st,int x){
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    
    // recursive call
    helper(st,x);
    
    st.push(num);
}
    stack<int> insertAtBottom(stack<int> St,int X){
        helper(St,X);
        return St;
    }
};
