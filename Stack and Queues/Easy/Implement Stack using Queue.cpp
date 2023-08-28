Approach: 2 Queues
For Push(x)
1. push x to q2
2. push q1 to q2 
3. pop element from q1 
4. swap q2 to q1

TC : O(N) 
SC : O(N) 

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
 
    void push(int x) {
     q2.push(x);
while(!q1.empty()){
       //from q1 -> q2
    q2.push(q1.front());
    q1.pop();
    }
        swap(q1,q2);
    }
    
    int pop() {
     int ans = top();
        q1.pop();
        return ans;
    }
    
    int top() {
        return (q1.front());
    }
    
    bool empty() {
        return q1.empty();
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------

Follow up question :  implement the stack using only one queue?


    




    
