Approach : Greedy

Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
Space Complexity: O(E) + O(V)

#include<bits/stdc++.h>
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
 priority_queue<pair<int,int>,vector<pair<int,int>>,
 greater<pair<int,int>>>pq;
vector<vector<pair<int,int>>> adj(n);
 vector<int> vis(n,0);
for(int i=0;i<edges.size();i++)
{
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
 int sum=0;
 pq.push({0,0});

 while(!pq.empty())
 {
     auto it = pq.top();
     pq.pop();
     int wt = it.first;
     int node= it.second;

    if(vis[node]==1) continue;
    vis[node] = 1;
    sum += wt;
    
    for(auto it : adj[node]){
        int adjNode = it.first;
        int edgeWt = it.second;
    if(!vis[adjNode]) {
        pq.push({edgeWt,adjNode});
    }
    }
 }
 return sum;
}
