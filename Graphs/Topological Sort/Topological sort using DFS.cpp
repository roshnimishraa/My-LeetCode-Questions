Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. 
  So, another O(V) time complexity.
Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack 
carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

1. use stack and vis array
2. traverse through all adj nodes and push into st
3. pop element from st and store in vector (topo sort) 
4. return topo sort 

class Solution
{
    private:
    void dfs(int node,int vis[],stack<int> &st,vector<int> adj[])
    {
        vis[node]=1;
        
    for(auto it : adj[node])
    {
        if(!vis[it] )
        {
            dfs(it,vis,st,adj);
        }
    }
    st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	 stack<int> st;
	 for(int i=0;i<V;i++)
	 {
	     if(!vis[i])
	     {
	         dfs(i,vis,st,adj);
	     }
	 }
	 vector<int> ans;
	 while(!st.empty())
	 {
	     ans.push_back(st.top());
	     st.pop();
	     
	 }
	 return ans;
	}
};
