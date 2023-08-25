

TC : O(2 * E) for undirected graph
     O(E)   for directed graph 

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
 
vector<int> ans[n];

// Creating the graph
for(int i=0;i<m;i++)
{
    int u = edges[i][0];
    int v = edges[i][1];

	// Adding adjecent nodes for undirected graph
    ans[u].push_back(v);
    ans[v].push_back(u);
}

// Create an adjacency list of size 'N'
vector<vector<int>> adj(n);

for(int i=0;i<n;i++)
{
    adj[i].push_back(i);
    for(int j=0;j<ans[i].size();j++)
    {
        adj[i].push_back(ans[i][j]);
    }
}
return adj;
}
