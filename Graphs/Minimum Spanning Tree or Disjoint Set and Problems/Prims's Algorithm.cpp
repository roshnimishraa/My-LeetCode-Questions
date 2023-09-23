Prim's Algorithm
1. Consider any vertex as source node
2. Find min edges with NO cycle 

Approach : Greedy

Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
Space Complexity: O(E) + O(V)

 Algorithm : 
1. Create a min-heap priority queue store weight and node of a graph
2. Make adjacency list if not give 
3. Initialize sum = 0 
4. Create a vector vis arrray initially assigned as 0 to keep track of vis node 
 if node is vis then do not consider its weight continue 
5. Traverse till pq is not empty 
 pop weight and node from pq 
a) if node is vis then continue 
b) if node is not vis then mark it as visited 
   and weight into sum sum += wt
6. Now, Iterate through adjNode 
mark adjNode as it[0] and edgeWeight it[1] 
if (adjNode is not visited in visited array)   
   pq.push({edgeWt,adjNode});
7. return sum 

 
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
