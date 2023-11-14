Hypothesis - Induction - Base Method 

void fun(int n) {
  if(n == 1){
cout<<n<<" ";
    return;
  }
fun(n-1);
cout<<n<<" ";
} 
