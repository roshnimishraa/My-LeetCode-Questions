Bellman Ford 
1. Single Source Shortest path
2. Works for -ve edges
3. Applicable in Directed Graph 
4. Helps to detect cycle in -ve cycle 
5. Edges can be in any order 
6. Relax all the edges N-1 times sequencially 
     Relax -> if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt
  
NOTE : 
If a graph PATH WEIGHT is less than 0 that means graph has negative cycle 
Eg. [u,v,wt]
[[3,1,2],[1,2,-2],[2,3,-1]] 
      Path Weight = -2 - 1 + 2 = -1 
-1 denotes graph has -ve cycle 

