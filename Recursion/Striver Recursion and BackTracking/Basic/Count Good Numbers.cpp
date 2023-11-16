class Solution {
public:
int mod = 1e9+7;
long long power(long long n,long long p){
    if(p ==0){
return 1;
    }
if(p < 0){
    p = 1/p;
    n = abs(n);
}
long long temp = power(n,p/2);
if(p % 2 == 0){
    return (temp*temp)%mod;
}
else {
    
return (n*((temp*temp)%mod))%mod;
}
}
    int countGoodNumbers(long long n) {
        int odd = n/2;
        int even = n/2 + n%2;
return (power(5,even) * power(4,odd))%mod;

    }
};
