Approach : DFS 

NOTE :
1. Bipartite Graph :- Color the graph with 2 colors such that NO Adjacent nodes have same color. 
2. Linear Grpahs with NO CYCLE are always Bipartite Graph 
3. Any graph with even cycle length can also be Bipartite Graph
4. Any graph with odd length cycle can never be Bipartite Graph

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one 
and a node in the other.

  
  
