TASK : 
Return min difference between maximum number of chocolates given to a student 
and minimum number of chocolates given to a student is minimum.

TC : O(NLOGN) 
SC :  O(1)

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n,
    long long m)
    {
    //sort in ascending order
    sort(a.begin(),a.end());
    
int i=0,j=m-1;
int mini = INT_MAX;

while(j<n)
{
    int diff = a[j]-a[i];
    mini = min(mini,diff);
    i++;
    j++;
}
        return mini;
    }   
};
