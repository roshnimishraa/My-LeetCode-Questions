1. only exists in DAG (Direct Acyclic Graph) 
2. DFS traversal is used 
3. Linear ordering of vertices such that if there is an edge between u and v, u appears before v in that ordering.

Approach : 
1. use a stack and a visited array
2. explore all the neighbours of node and push into stack and mark 1 in visited array 
3. if stack is empty pop of out and push into ans vector 

why DFS Traversal ?
	DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path,
then it backtracks on the same path and traverses other unvisited nodes.

Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, 
where N = no. of nodes.

Eg. For the edges connection 
5->0
4->0
5->2
2->3
3->1
4->1

Topological sort is : 5  4  3  2  1  0 or 4  5  2  3  1  0

  Implementation 
  
  class Solution
{
    private:
    void dfs(int node,int vis[],vector<int> adj[],stack<int> &st)
    {
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it])
            dfs(it,vis,adj,st);
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    //push in st
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
