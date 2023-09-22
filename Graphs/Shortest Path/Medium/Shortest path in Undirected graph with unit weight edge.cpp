Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
Expected Space Complexity: O(N)

Alogrithm : BFS Approach 
1. Make a adj List store nodes 
2. take a dist array initialized with INT_MAX and mark source as 0
3. take a queue push source node 
4. iterate in queue till it gets empty
i) take out front node from q and expore its adjacent nodes
ii) if (dist[currNode]+1 < dist[node] ) then dist[node] = dist[currNode] + 1
iii) push currNode in queue 
5. if dist[i] == INT_MAX then mark dist[i] = -1
6. return dist

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, 
    int N,int M, int src){
    
        vector<int> adj[N];
        
    for(int i=0;i<M;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
 vector<int> dist(N);
    for(int i=0;i<N;i++)
    {
        dist[i]=1e9;
    }
    dist[src]=0;
    queue<int> q; // to store node
    q.push(src);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
    for(auto it : adj[node])
    {
        if(dist[node] + 1 < dist[it])
        {
            dist[it] =dist[node]+1;
            q.push(it);
        }
    }
    }
    vector<int> ans(N,-1);
    
   for (int i = 0; i <dist.size(); i++) {
            if (dist[i] ==  1e9) 
            dist[i] = -1;
        }

    return dist;
    }
};
