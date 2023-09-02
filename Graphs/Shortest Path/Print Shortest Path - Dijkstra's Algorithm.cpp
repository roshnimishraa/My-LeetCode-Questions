1, We would be using a min-heap and a distance array of size V (where ‘V’ are the number of nodes in the graph) initialized with
infinity (indicating that at present none of the nodes are reachable from the source node) and initialize the distance to source node as 0.
2. We push the source node to the queue along with its distance which is also 0.
3. For every node at the top of the queue, we pop the element out and look out for its adjacent nodes. If the current reachable distance 
is better than the previous distance indicated by the distance array, we update the distance and push it into the queue.

Time Complexity: O( E log(V) ) + O(V) , Where E = Number of edges and V = Number of Nodes.
Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.

APPROACH : PRIORITY QUEUE
1. Take a priority queue (MIN-HEAP) 
2. Hence graph consists edges weight take pair of adjList. Since indexing start from 1 take v+1 size list push u,v,wt in adjList
3. take a vector of dist[] and parent[] of size v+1 initially dist[i] = INT_MAX
and parent node initlially of itself parent[i]= i
4. assign distance of src node as 0 and push it in priority queue
5. traverse throught pq till it gets empty
    take top of the pq and
pop {dis,node} from q 
6. Now iterate through adjNode 
     edgeWeight = it.second
      adjNode = it.first 
i) if(dis + edgeWeight < dist[adjNode]) then update dist[adjNode] = dist + edgeWeight and 
push dist[adjNode],adjNode in pq and
update parent[adjNode] = node
7. check if all nodes are reachable if not reachable return {-1} 
8. take a vector path to store path 
the maximum shortest can be number of nodes =v
i) iterate through parent[node] != node 
      push node in vector path
  update parent -> node =parent[node]
ii) add src node in vector 
9. Reverse the vector 
10. return path 

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
// min heap 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

vector<pair<int,int>> adj[n+1];

  for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

vector<int> dist(n+1,1e9);

vector<int> parent(n+1);
for(int i=1;i<=n;i++)
    parent[i]=i;

dist[1]=0;

pq.push({0,1});

while(!pq.empty()){
    auto it = pq.top();
    pq.pop();
    
    int node = it.second;
    int dis = it.first;
    
    for(auto it : adj[node]){
        int edgeWeight = it.second;
        int adjNode = it.first;
        
    if(dis + edgeWeight < dist[adjNode])
    {
        dist[adjNode] = dis + edgeWeight;
        pq.push({dist[adjNode],adjNode});
       //node where it came from 
       parent[adjNode]=node;
    }
    }
}

if(dist[n]== 1e9) return {-1};

int node=n;
vector<int> path;
while(parent[node] != node){
    path.push_back(node);
    node = parent[node];
}
path.push_back(1);
reverse(path.begin(),path.end());
return path;
    }
    
};

















