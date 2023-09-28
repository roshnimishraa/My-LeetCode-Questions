TC : O(N LOG N) + theta (N) ~ O(N LOG N) 
SC : O(N) 

Algorithm 
1. Create a vector of pair to insert start and End time 
2. Sort According to Finish Time 
3. Initialize solution or count as first activity 
4. Do following for remaining activities : 
a) if current activity is less than with last picked activity(End time) in the solution then ignore the current activity
b) else add the current activity to the count

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
static bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> vec;
        int prev =0;
        int count=1;
        
    for(int i=0;i<n;i++)
    {
        vec.push_back({start[i],end[i]});
    }
    
    sort (vec.begin(),vec.end(),cmp);
    
for(int i=1;i<n;i++)
{
    if(vec[i].first > vec[prev].second)
    {
        prev = i;
        count++;
    }
}
return count;
    }
};
