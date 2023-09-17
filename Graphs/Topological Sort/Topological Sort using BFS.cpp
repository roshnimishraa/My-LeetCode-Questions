Kahn's Algorithm ~ Topological sort using BFS

Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes)

/*   Implementation  */

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	 int indegree[V] ={0}; //initially indegree of nodes is 0 
	 
	//calculate indegree 
	for(int i=0;i<V;i++)
	{
	   for(auto it : adj[i]){
	       indegree[it]++;
	   }
	}
	queue<int> q;
	for(int i=0;i<V;i++){
	   if(indegree[i] == 0) {
	       q.push(i);
	   }
	}
	//store ans in vector 
	vector<int> topo;
	//push 0 indegree node in queue
	while(!q.empty())
	{
	    int node =q.front();
	   q.pop();
	   
	  topo.push_back(node);
	  
	 // traverse all its adjacent nodes 
	for(auto it : adj[node])
	{
	   // node is in used or store in vector ans 
	   // therefore decrease indegree
	   indegree[it]--;
	   
	  //if after decreasing indegree it becomes 0 then push 
	  // into queue
	 if(indegree[it] == 0)
	  q.push(it);
	}
	   
	}
	return topo;
	}
};
