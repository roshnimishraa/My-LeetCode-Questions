Appraoch:
1. find right most set bit mask 
2. after cal rsbm mark as 0 and increase count 
     repeat this step until n!=0 

int countSetBits(int N)
{
    int count=0;
    while(N!=0)
    {
        int rsbm = N & -N;
        N-= rsbm;
        count++;
    }
return count;
}
