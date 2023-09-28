Algorithm : 
1. Find Sunday = S/7
2. Find Buying days = S- Sunday
3. TotalFood = S * M
4. Check if TotalFood is multiple of N 
  then return ans = TotalFood/N
else 
  // for N=16 , M = 2 , S = 10
  TotalFood = S * M = 20 
  20/16 = 1 days 
  ans = 1 + 1= 2 days 
  return TotalFood/N + 1
5. Corner Case handle 
if(ans <= buying) return ans 
else 
  //for N=1, M=1 , S= 10
  return -1 

  TC : O(1) 
SC : O(1) 
   
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sunday = S/7;
        int buying = S-sunday;
        int totalFood = S * M;
        int ans=0;
    //if totalfood is multiple of N 
if(totalFood % N == 0)
{
    ans = totalFood / N ;
}
else {
    ans =(totalFood / N) + 1; 
}
if(ans <= buying)
{
    return ans;
}
else{
    return-1;
}
    }
};
