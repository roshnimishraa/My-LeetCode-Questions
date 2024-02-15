Approach : Kahn's Algorithm ~ Topological sort using BFS

Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used 
in BFS(where N = no.of nodes)

Algorithm : 
1. Take indegree of all nodes.
2. push nodes in Queue with indegree 0
3. pop node from Queue store node in vector ans 
and reduce the indegree of node 
    if indegree == 0 then push into Queue 


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	 int indegree[V]={0};
	 for(int i=0;i<V;i++)
	 {
	    for(auto it:adj[i])
	    {
	        indegree[it]++;
	    }
	 }
	 queue<int> q;
	 
	 for(int i=0;i<V;i++)
{
    if(indegree[i]==0)
    {
        q.push(i);
    }
}
vector<int> ans;
while(!q.empty())
{
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for(auto it:adj[node])
    {
        indegree[it]--;
        if(indegree[it]==0)
        q.push(it);
    }
}
return ans;
}
};
