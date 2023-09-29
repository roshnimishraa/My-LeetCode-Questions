Time Complexity:O(V)
Space Complexity:O(1)
  
vector<int> MinimumCoins(int V)
{
    int arr[]= {1,2,5,10,20,50,100,500,1000};
    int n=9;
        vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        while(V >= arr[i])
        {
      V-=arr[i];
            ans.push_back(arr[i]);
              
        }
    }
    return ans;
}
