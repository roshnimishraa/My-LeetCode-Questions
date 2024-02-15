Same as Course Scheduler - I but 
1. condition of true [0,1] course 0 should be taken before 1 and 
2. return vector 

       
class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites)
    {
        int n = prerequisites.size();
   vector<vector<int>> adj(N);
for(auto it:prerequisites)
{
adj[it[1]].push_back(it[0]);
}
// kahn's algo
vector<int> indegree(N,0);
for(int i=0;i<N;i++)
{
for(auto it:adj[i])
{
    indegree[it]++;
}
}
queue<int> q;
for(int i=0;i<N;i++)
{
    if(indegree[i]==0)
    {
q.push(i);
    }
}
vector<int> ans;
while(!q.empty()){
    auto node = q.front();
    q.pop();
ans.push_back(node);
for(auto it:adj[node])
{
indegree[it]--;
if(indegree[it] == 0)
{
    q.push(it);
}
}
}
if(ans.size() == N) return ans;
else return {};
    }
};
