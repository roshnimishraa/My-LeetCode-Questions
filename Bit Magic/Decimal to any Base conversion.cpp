Approach : 
i) Convert 
ii) Fit into bits 

Eg. (634) = ( ) convert into octal 

After solving LCM by num % 8 & n = n/base 
  storing remainder n% 8 = digit 
we get 2 7 1 1 now we have reverse it for ans  
power = 10^0 = 1
rev += dig * power;

2* 10^0 + 7*10^1 + 1*10^2 + 1*10^3 = 2 + 70 + 100 + 1000 = 1172 

int main() {
    int base = 2;
    int n = 5;
    int power =1; //10^0 = 1
    int rv =0;
while(n>0)
{
    int dig = n % base;
    n = n/base;
    
    rv += dig * power;
    power  = power*10; 
}

return rv;
    
}
