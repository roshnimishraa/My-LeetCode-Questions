Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M).
Where N= number of vertices and M= number of edges.
Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.

Initial configuration:
1. Adjacency List 
2. Visited Array
3. Stack
4. Distance Array intially mark infinity and take src node dist as 0

Approach : Topological Sort using DFS
given source =0 if for any node shortest path is not exist return -1
 
1. Make adj list 
2. Find the topoSort using DFS 
3. Takes the nodes out of stack and explore its neighbour dist and relax the edges (using dis[] array) 
4. Initialize dist[] initially as INT_MAX and mark source node as 0 and find shortest distance
5. if(dist[node] + wt < dist[v]) then update dist[v] as dist[node] + wt 
6. At the end, check if all nodes assigned shortest dist or not 
   if any node dist[i] = INT_MAX then return -1
7. return dist 

IMPLEMENTATION 

// User function Template for C++
class Solution {
    private:
    void dfs(int node,int vis[],vector<pair<int,int>> adj[],stack<int> &st)
    {
        vis[node]=1;
        
    for(auto it : adj[node])
    {
        int v = it.first;
        if(!vis[v])
        {
            dfs(v,vis,adj,st);
        }
    }
    st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
// adj list -> {node,wt}
vector<pair<int,int>> adj[N];
int vis[N]={0};

// ADJ LIST 
    for(int i=0;i<M;i++)
    {
        int u=edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    // OR ADJ LIST 
//     for (auto it : edges) {
// 			adj[it[0]].push_back({it[1], it[2]});
// 		}
    
    // find dfs toposort 
stack<int> st;
for(int i=0;i<N;i++)
{
    if(!vis[i])
    {
        dfs(i,vis,adj,st);
        
    }
}

// find shortest dist 
vector<int> dis(N);
for(int i=0;i<N;i++)
{
    // dis[i] = INT_MAX;
    dis[i]=1e9;
}
//dist of source =0 src give as 0
dis[0]=0;

while(!st.empty())
{
auto node = st.top();
st.pop();

// explore adj nodes
for(auto it : adj[node])
{
    int v = it.first;
    int wt = it.second;
    
    if(dis[node] + wt < dis[v])
{
    dis[v] = dis[node]+wt;
}
}
}
  for (int i = 0; i <dis.size(); i++) {
            if (dis[i] ==  1e9) dis[i] = -1;
        }

return dis;
    }
};
