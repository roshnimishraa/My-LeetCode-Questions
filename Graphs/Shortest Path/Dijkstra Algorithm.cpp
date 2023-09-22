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

TC : E log V, 
where E = Total no. of Edges and V = No. of Nodes

Algorithm 

1. Create a Min-Heap Priority Queue store {dist,node}
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq

2. create a distance vector array 
a) initialize all nodes as INFINITY
b) assign source node as 0 

3. push src node and 0 as distance in pq

4. Iterate through pq get ({dist,node})
       dist = pq.top().first
        node =pq.top().second
and explore it's adjacent Nodes

5. Traverse for Adjcent Node and assign edge Weight as 
	// Adj List = {node,weight}
    edgeWeight = it[1] 
     adjNode = it[0] 
 
6. update shortest path 
    if(dist + wt < dist[adjNode] then update adjNode 
      dist[adjNode] = dist + wt
push in priority queue 
pq.push({dist[adjNode],adjNode})

7. return dist

**********************IMPLEMENTATION*****************************************************

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], 
    int S)
    {
       vector<int> dist(V);
       for(int i=0;i<V;i++) dist[i]=1e9;
       dist[S]=0;
       
    //   pq {dist,node} 
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     
    pq.push({0,S});
    
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int distance = it.first;
        int node = it.second;
        
    // traverse neighbour nodes
    for(auto it : adj[node])
    {
        // adj List -> {node,weight}
        int adjNode = it[0];
        int weight = it[1];
        
    if(distance + weight < dist[adjNode])
    {
        dist[adjNode] =distance + weight;
        // pq -> {dist,node}
        pq.push({dist[adjNode],adjNode});
    }
    }
    }
    return dist;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Dijkstra Algorithm using SET 

Time Complexity : O( E log(V) ) 
Where E = Number of edges and V = Number of Nodes.
Space Complexity : O( |E| + |V| ) 
Where E = Number of edges and V = Number of Nodes.


Algorithm 

1. We would be using a set and a distance array of size V (where ‘V’ are the number of nodes in the graph) initialized with infinity
(indicating that at present none of the nodes are reachable from the source node) and initialize the distance to source node as 0.
2. We push the source node to the set along with its distance which is also 0.
3. Now, we start erasing the elements from the set and look out for their adjacent nodes one by one. If the current reachable distance is better than the
previous distance indicated by the distance array, we update the distance and insert it in the set.
4. A node with a lower distance would be first erased from the set as opposed to a node with a higher distance. By following step 3, until our set becomes empty, we would get the minimum distance from the source
node to all other nodes. We can then return the distance array. 
5. The only difference between using a Priority Queue and a Set is that in a set we can check if there exists a pair with the same node but a greater distance 
than the current inserted node as there will be no point in keeping that node into the set if we come across a much better value than that.
So, we simply delete the element with a greater distance value for the same node.
	
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    set<pair<int,int>> st;
   vector<pair<int,int>> adj[vertices];
  for(int i=0;i<edges;i++){
          int u=edge[i][0];
		  int v=edge[i][1];
          int wt=edge[i][2]; 
		  adj[u].push_back({v,wt});
		  adj[v].push_back({u,wt});
   }
	vector<int>dist(vertices,INT_MAX);
        
st.insert({0,source});
dist[source]=0;

while(!st.empty())
{
 //get the it val 
 auto it = *(st.begin());
 int dis = it.first;
 int node = it.second;
 st.erase(it);
 
 for(auto it : adj[node])
 {
 			int adjnode=it.first;
			int edgewt=it.second;
            
	if(dis+edgewt<dist[adjnode]){		
     if(dist[adjnode] != INT_MAX){
       st.erase({dist[adjnode],adjnode});
}
     dist[adjnode] = dis + edgewt;
     st.insert({dist[adjnode],adjnode});
}
 }
}
return dist;
}


















