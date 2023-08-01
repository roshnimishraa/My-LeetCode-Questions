Brute Force : making push operation costly
TC: O(N)
SC : O(2N)

Approach : 
For Push 
1. s1-> s2
2. x-> s1
3. s2->s1

For Pop : 
s1.pop();


------------------------------------------------------------------------------------------------------------------------------------
Efficient Approach : making pop operation costly
TC : Amortised O(1) { In worst case it can be O(N) }  
SC : O(2N)

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        input = stack<int>();
        output = stack<int>();
    }
    
    void push(int x) {
        input.push(x);
       
    }
    
    int pop() {
       
       
      if(output.empty() ==true) {
            while(input.empty() == false){
               output.push(input.top());
            input.pop();
         
            }
               
        }
         int ans =output.top();
        output.pop();
     return ans;   
    }
    
    int peek() {
    
       if(output.empty()){
           while(!input.empty()){
               output.push(input.top());
               input.pop();
           }
       }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

