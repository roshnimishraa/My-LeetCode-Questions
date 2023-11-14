Hypothesis - Induction - Base Method 

Print 1 to N 
void fun(int n) {
  if(n == 1){
cout<<n<<" ";
    return;
  }
fun(n-1);
cout<<n<<" ";
} 


Print N to 1 

void fun(int n) {
  if(n == 1){
cout<<n<<" ";
    return;
  }
cout<<n<<" ";  
fun(n-1);

} 
