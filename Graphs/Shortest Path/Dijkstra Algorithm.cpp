Dijkstra Algorithm ~ Single Source Shortest Path 
Very Famous Greedy Algorithm and give Optimal solution 

>> Condition : 
1. Works only for Connected Graph
2. It works only for those graph that don't contain any negative weight edge -> Because for negative weight it will fall in INFINITE LOOP 
3. It only provides the value or cost of the shortest path 
4. Works for both directed and undirected graph

It can be implemented using : 
1. Queue : More Slow 
2. Priority Queue : Slow 
3. Set : Fast (TC)

**************************************************************************************************************************************************************
  Dijktra Algorithm using Priority Queue 

TC : E log V, where E = Total no. of Edges and V = No. of Nodes

Algorithm 

1. Create a Min-Heap Priority Queue store {dist,node}
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq

2. create a distance vector array 
a) initialize all nodes as INFINITY
b) assign source node as 0 

3. push src node and 0 as distance in pq

4. Iterate through pq get 
       dist = pq.top().first
        node =pq.top().second
and explore it's adjacent Nodes

5. Traverse for Adjcent Node and assign edge Weight as 
    edgeWeight = it[1] 
     adjNode = it[0] 
 
6. update shortest path 
    if(dist + wt < dist[adjNode] then update adjNode 
      dist[adjNode] = dist + wt
push in priority queue 
pq.push({dist[adjNode],adjNode})

7. return dist

**********************IMPLEMENTATION*****************************************************

#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
vector<pair<int,int>>adj[vertices];
for(auto it : edge){
adj[it[0]].push_back({it[1],it[2]});
adj[it[1]].push_back({it[0],it[2]});
}
vector<int>dist(vertices,INT_MAX);
dist[source]=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,source});

while(!pq.empty()){
int node=pq.top().second;
int dis=pq.top().first;
pq.pop();
for(auto it: adj[node]){
int adjNode=it.first;
int wt=it.second;

if(dis+wt<dist[adjNode]){
dist[adjNode]=dis+wt;
pq.push({dist[adjNode],adjNode});

}
}
}
return dist;

}

