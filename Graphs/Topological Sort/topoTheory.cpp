Topological Sorting : 
i) Linear ordering of vertices such that if there is an edge between u and v, u appears before v in that ordering 
ii) Only exists in Directed Acyclic Graph (DAG) 

Topological Sort using DFS : 
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. 
  So, another O(V) time complexity.
Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack 
carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

1. use stack and vis array
2. traverse through all adj nodes and push into st
3. pop element from st and store in vector (topo sort) 
4. return topo sort 
