Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)


class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        sort(candies,candies+n);
        
      int mini=0;
     int buy=0;
     int free=n-1;
    //  for min candies
    while(buy <= free)
    {
        mini = mini + candies[buy];
        buy++;
        free = free - K;
    }
    
    int maxi=0;
    buy = n-1;
    free =0;
    while(free <= buy )
    {
        maxi = maxi + candies[buy];
        buy--;
        free = free + K;
    }
     vector<int> ans;
     ans.push_back(mini);
     ans.push_back(maxi);
     return ans;
    }
};
