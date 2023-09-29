TC : O(N LOG N) + O(N) ~ O(N LOG N) 
SC : O(1) 

ALGORITHM : 
1. Calculate ratio (value/weight) for every item.
2. Sort all item in decreasing order of the ratio/weight.
3. Initialize : res =0 , curr_cap = given_cap
4. Do following for every item I in sorted order 
a) else if(I.weight <= curr_cap) 
    {
       curr_cap -= I.weight
         res += I.value
    }
b) else {
  res += (I.value) * (curr_cap / I.weight) 
  return res
5. return res 
  }


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
   static bool cmp(Item a ,Item b)
    {
     double r1 = (double)a.value/a.weight;
     double r2 = (double)b.value/b.weight;
     
     return r1 > r2; // sort in descending order
}
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    sort(arr,arr+n,cmp);
    int currWeight =0;
    double finalValue = 0.0;
    
    for(int i=0;i<n;i++)
    {
        if(currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = W- currWeight;
 finalValue += (arr[i].value / (double)arr[i].weight)
                 * (double) remain;
    break; 
        }
    }
    return finalValue;
    }
        
};
