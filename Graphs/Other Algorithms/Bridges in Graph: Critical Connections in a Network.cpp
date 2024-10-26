### Approach: DFS + Tarjan's Algorithm

Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V)
for the three arrays i.e. tin, low, and vis, each of size V.

class Solution {
    private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[],vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it: adj[node])
        {
            if(it == parent) continue;
            if(vis[it] == 0)
            {
              dfs(it, node,vis, adj, tin,low,bridges);
            low[node] = min(low[it], low[node]);
 
 //when we get low of child is greater than tin of the node it means there is only path to cover child that's why {node, it} will be our critical connections or bridge 
            if(low[it] > tin[node])
            {
                bridges.push_back({it,node});
            }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int tin[n]; //Time of Insertion
        int low[n]; // min time of insertion

        vector<vector<int>> bridges;
    dfs(0, -1, vis, adj, tin, low, bridges);

    return bridges;
    }
};
