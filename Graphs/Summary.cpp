1. Time Complexity of DFS & BFS -> O(V) + O(E) 
 BFS : Queue and vis 
 DFS : Recursion and vis 

2. Rotten Oranges : Return min time so traverse level wise (BFS) 

3. Cycle Detection in Undirected Graph
a) DFS -> parent & node & vis
b) BFS -> queue {node,parent}, vis

4. Detect Cycle in Directed Graph 
a) DFS -> vis & pathVis 
b) BFS -> indegree & count
 if there is cycle the count < N and is there is no cycle then count == N 

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

8. Prerequisite Tasks-I/ Course Schedule-I [1,0],[2,1] 
i) Do TopoSort BFS Traversal(Kahn's Algo) and if no cycle then return true
 if Cycle return false 
ii)  Course Schedule-I [0,1],[1,2] 

9. Shortest Path in Directed Acyclic Graph(DAG) ~ TopoSort DFS 
Time Complexity: O(N+M)
Space Complexity : O(N + M) 
 
i. Make adj list 
ii. Find the topoSort using DFS 
iii. Takes the nodes out of stack and explore its neighbour dist and relax the edges (using dis[] array) 
iv. Initialize dist[] initially as INT_MAX and mark source node as 0 and find shortest distance
v. if(dist[node] + wt < dist[v]) then update dist[v] as dist[node] + wt 
vi. At the end, check if all nodes assigned shortest dist or not 
   if any node dist[i] = INT_MAX then return -1
vii. return dist 

10. Shortest Path in Undirected Graph with Unit Weights ~ BFS 
Expected Time Complexity: O(N + 2E), SC : O(N + E) 

i. Make a adj List store adjList -> (nodes) 
ii. take a dist array initialized with INT_MAX and mark source as 0
iii. take a queue push source node 
iv. iterate in queue till it gets empty
a) take out front node from q and expore its adjacent nodes
b) if (dist[currNode]+1 < dist[node] ) then dist[node] = dist[currNode] + 1
c) push currNode in queue 
v. if dist[i] == INT_MAX then mark dist[i] = -1
vi. return dist
 
11. Dijkstra Algorithm(Single Source Shortest Path for +ve egdes) ~ Priority Queues 
TC : O(E log V) 
Algorithm : 
i. Create a Min-Heap Priority Queue store {dist,node}
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq

ii. create a distance vector array 
a) initialize all nodes as INFINITY
b) assign source node as 0 

iii. push src node and 0 as distance in pq

iv. Iterate through pq get ({dist,node})
       dist = pq.top().first
        node =pq.top().second
and explore it's adjacent Nodes

v. Traverse for Adjcent Node and assign edge Weight as 
	// Adj List = {node,weight}
    edgeWeight = it[1] 
     adjNode = it[0] 
 
vi. update shortest path 
    if(dist + wt < dist[adjNode] then update adjNode 
      dist[adjNode] = dist + wt
push in priority queue 
pq.push({dist[adjNode],adjNode})

vii. return dist

12. Bellman Ford(Single Source Shortest path for -ve edges)
TC : O(V * E) 
SC : O(V) 
Algorithm : vector dist[]  
i. take a dist[] initialized with MAX value 
ii. assign source node as 0 
iii. iterate till N-1 times and 
       iterate through all the edges 
a) Update dist if 
   dist[u] != 1e8 &&  dist[u] + wt < dist[v] 
iv. if the graph for Nth iteratation distance get reduced that means it has -ve cycle then it will not give shortest
path therefore again iterate all the edges and check 
if(dist[u] != 1e8 && dist[u] + wt < dist[v] return -1 
v. return dist

13. floyd Warshall Algorithm (MultiSource Directed Graph, -ve cycle detect) 
TC : O(N)^3
SC : O(N)^2 for storing adj matrix 

Algorithm ~ adj matrix 
Traverse on all paths using three for loop via traversing through every node to find shortest path 
i. take adj/cost matrix 
ii. node to node distance is always 0 and distance from vertex 0 is gets same 
 mark unreachable node as INT_MAX 
mark diagonal (i==j) as 0  
Assign initial cost to node 
iii. Make resultant matrix via every node traverse through all the edges
iv. For node n traverse -> shortest path matrix found 

14. Minimum Spanning Tree 
i) N nodes N-1 edges 
ii) Connected & No Cycle 
iii) Two Method to find MST - a) Prim's Algorithm (b) Kruskal's Algorithm 
	
15. Prim's Algorithm (find the sum of weights of the edges of the Minimum Spanning Tree.) 
TC : O(E log E) 
SC : O(V + E) 
i) Take a adj list store {node,wt} 
ii) Take a min-heap priority queue store {wt , node} 
     push src =0 in pq 
iii) Take a vis[] initialize with 0
iv) Iterate till pq get empty
a) take out of pq {wt,node} 
b) if node is already vis then do not do anything continue
c) if node is not visited then mark it as vis and calculate sum += wt
d) Traverse through neighbour nodes {adjNode,edgeWt} 
      if adjNode is not vis then push {adjNode,edgeWt} in pq
v) return sum 
