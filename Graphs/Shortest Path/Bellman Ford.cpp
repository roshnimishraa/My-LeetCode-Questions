Bellman Ford 
1. Single Source Shortest path
2. Works for -ve edges
3. Applicable in Directed Graph 
4. Helps to detect cycle in -ve cycle 
5. Edges can be in any order 
6. Relax all the edges N-1 times sequencially 
     Relax -> if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt
  
NOTE : 
1. If a graph PATH WEIGHT is less than 0 that means graph has negative cycle 
Eg. [u,v,wt]
[[3,1,2],[1,2,-2],[2,3,-1]] 
      Path Weight = -2 - 1 + 2 = -1 
-1 denotes graph has -ve cycle 

2. Why N-1 times iteration for Relaxation of Edges or to find Shortest path 
 Since in a graph of N nodes, in worst case It will take N-1 edges to reach from the first to last, 
thereby we iterate for N-1 times

>>>> For graph which takes more than N-1 edges for any path, it is not possible to find Shortest path 

3. How to detect Negative Cycle in Bellman Ford Algorithm 
  On Nth iteration, the relaxation will be done and if dist[] gets reduced (that means it has loop) -> the graph has -ve cycle 

TC : O(V * E) 
SC : O(V) 
Algorithm : vector dist[]  
1. take a dist[] initialized with MAX value 
2. assign source node as 0 
3. iterate till N-1 times and 
       iterate through all the edges 
i) Update dist if 
   dist[u] != 1e8 &&  dist[u] + wt < dist[v] 
4. if the graph for Nth iteratation distance get reduced that means it has -ve cycle then it will not give shortest
path therefore again iterate all the edges and check 
if(dist[u] != 1e8 && dist[u] + wt < dist[v] return -1 
5. return dist

vector<int> bellmonFord(int V, int m, int src, vector<vector<int>> &edges) {
   vector<int> dist(V,1e8);
dist[src]=0;
   for(int i=0;i<V-1;i++)
   {
for(auto it : edges)
{
    int u = it[0];
    int v = it[1];
    int wt = it[2];

// update dist 
if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
    dist[v] = dist[u]+wt;
}
}
   }

// if -ve cycle then return -1 
for(auto it : edges)
{
     int u = it[0];
    int v = it[1];
    int wt = it[2];

if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
   return {-1};
}
}
return dist;
}
