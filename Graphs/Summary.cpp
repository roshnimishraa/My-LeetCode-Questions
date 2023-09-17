1. Time Complexity of DFS & BFS -> O(V) + O(E) 
 BFS : Queue and vis 
 DFS : Recursion and vis 

2. Rotten Oranges : Return min time so traverse level wise (BFS) 

3. Cycle Detection in Undirected Graph
a) DFS -> parent & node & vis
b) BFS -> queue {node,parent}, vis

4. Detect Cycle in Directed Graph 
a) DFS -> vis & pathVis
b) BFS -> indegree & count if count < N then there is cycle 

5. DFS Approach (Islands) 
i) No. of Islands -> DFS traversal & vis & count 
ii) No. of Distinct Island -> DFS & vis & vector of pair of list & set to store unique list return st.size() 
  
6. Bipartite Graph 
 Time complexity: O(V+E).
Auxiliary Space: O(V)
i) BFS Approach : 
Take queue and color(v,-1) take color initlially 0 
ii) DFS Approach : 
Take currentColor,color,node,adj

7. Topological Sort 
a) DFS : use stack and vis array and ans vec to store topo sort  
TC : O(V+E)+O(V)
b) BFS(Kahn's Algorithm) : use indegree array,queue 

  
