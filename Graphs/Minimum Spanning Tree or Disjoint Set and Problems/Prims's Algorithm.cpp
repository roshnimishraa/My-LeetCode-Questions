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

 
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      //adj list -> {wt} 
      // pq-min heap -> {wt,node}
      // vis[]
      //mst []
      
   priority_queue<pair<int,int>,vector<pair<int,int>>,
   greater<pair<int,int>>> pq;
   
   vector<int> vis(V,0);
   pq.push({0,0}); //{wt,node}
      
     int sum=0;
     while(!pq.empty())
     {
         auto it = pq.top();
         pq.pop();
         int wt =it.first;
         int node = it.second;
         
    //if node already vis then don't do anything
if(vis[node] == 1) continue;

//if node is not vis then mark it as vis and
// cal sum 
vis[node] = 1;
sum += wt;

//traverse through adjacent nodes
for(auto it : adj[node])
{
    int adjNode = it[0];
    int edgeWeight = it[1];
    
    if(!vis[adjNode])
    {
        pq.push({edgeWeight,adjNode});
    }
}
     }
     return sum;
    }
};
