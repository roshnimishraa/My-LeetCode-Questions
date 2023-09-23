Prim's Algorithm
1. Consider any vertex as source node
2. Find min edges with NO cycle 

Approach : Greedy

Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
Space Complexity: O(E) + O(V)

 Algorithm : 

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
