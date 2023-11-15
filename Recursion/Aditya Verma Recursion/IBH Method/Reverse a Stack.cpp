//User function Template for C++

class Solution{
public:
void insertAtBottom(stack<int> &st,int ele){
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    
    int num = st.top();
    st.pop();
    
    // recursive call 
    insertAtBottom(st,ele);
    
    st.push(num);
    
}
    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
    int num = st.top();
    st.pop();
    
    // recursive call 
    Reverse(st);
    
    insertAtBottom(st,num);
    
    }
};
