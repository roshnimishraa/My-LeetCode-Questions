// Using Build in Function _builtin_popCount TC : O(N LOG N)

class Solution {
public:
    vector<int> countBits(int n) {

vector<int> res(n+1);
for(int i=0;i<=n;i++){
    res[i] = __builtin_popcount(i);
    
}
return res;
    }
};


1 - 1             
2 - 01
3 - 011 
4 - 100 
5 - 101 
6 - 110 
7 - 111
8 - 1000
9 - 1001
10 - 1010 

  For Even no. of 1's = (Num/2) 
  for 10 = (10/2) = 5 that means no. of 1 in 10 and 5 is 2 
  for 4  = 4/2 = 2 has 1 bit of 1 then 4 also has 1 bit of 1

For Odd no. of 1's = (num/2) + 1
  for 9 = (9/2) + 1 = 4 has 1 bit of 1 + 1 = 2 that means 9 has 2 bits of 1's

  
//Using Bitwise Operator 
 class Solution {
public:
    vector<int> countBits(int n) {
vector<int> result(n+1);
if(n == 0) return result;
result[0] = 0;

for(int i=1;i<=n;i++){
    if(i%2 != 0){
result[i] = result[i/2]+1;
    }
    else{
        result[i]= result[i/2];
    }
}
return result;
    }
};
