Approach : Kahn's Algorithm ~ Topological sort using BFS

Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used 
in BFS(where N = no.of nodes)

Algorithm : 
1. take a array of indegree intially assigned 0 
2. now put indegree of nodes in array 
3. take a queue insert node with indegree 0 into the queue and explore its adjacent nodes
4. while taking nodes from indegree array and pushing into q decrease indegree of node.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	   
	  for(int i=0;i<V;i++)
	  {
	   for(auto it : adj[i])
	   {
	       indegree[it]++;
	   }
	  }
	
	queue<int> q;
	for(int i=0;i<V;i++)
	{
	    if(indegree[i]==0){
	        q.push(i);
	    }
	}
	vector<int> topo;
	while(!q.empty())
	{
	    int node = q.front();
	    q.pop();
	    topo.push_back(node);
	    
	   for(auto it : adj[node])
	   {
	       indegree[it]--;
	       
	   if(indegree[it]==0){
	       q.push(it);
	   }
	   }
	}
	return topo;
	}
};
