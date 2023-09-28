TC : O(N LOG N) 
SC : O(N) 

class Solution{
public:
static bool cmp(pair<pair<int,int>,int> a,
pair<pair<int,int>,int> b) 
{
    return a.first.second < b.first.second;
}

    vector<int> maxMeetings(int n,vector<int> &start,
    vector<int> &end)
    {
        
    vector<pair<pair<int,int>,int>> vec;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        vec.push_back({{start[i],end[i]},i});
        
    }
    sort(vec.begin(),vec.end(),cmp);
    
    ans.push_back(vec[0].second+1);
    
    int endAns = vec[0].first.second;
    for(int i=1;i<n;i++)
    {
        if(vec[i].first.first > endAns)
        {
            ans.push_back(vec[i].second+1);
            endAns = vec[i].first.second;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};
