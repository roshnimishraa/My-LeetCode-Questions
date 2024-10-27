### Approach : Min-Heap

Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, 
there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node,
we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and
for that, we need a logE time complexity. So this will result in the second O(E*logE). 

Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the
visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.

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
