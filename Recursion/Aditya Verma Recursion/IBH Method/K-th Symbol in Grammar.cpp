//T.C : O(N)
//S.C : O(N) Stack space

Logic 
for s1 : 0 
    s2 : 0 1 
    s3 : 0 1 1 0 
    s4 : 0 1 1 0 1 0 0 1 
    s5 : 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 

Eg. n = 5, k = 4 
  s5 kth character return 
output : 1 

Observation
  length = 2^(n-1)
if k<=mid  solve(n,k) -> solve(n-1,k) 
else solve(n,k) -> !solve(n-1,k-mid) 


class Solution {
public:
int solve(int n,int k){
    //base case 
    if(n == 1 && k == 1){
        return 0;
    }

int length = pow(2,n-1);
int mid = length/2;

if(k <= mid){
    return solve(n-1,k);
}
else {
    return !solve(n-1,k-mid);
}
}
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};
