Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N)
  { for adding the final values of the shortest path in the resultant array} ~ O(N+2M). 
Where N= number of vertices and M= number of edges.
Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N)
  {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

TC : O(N + 2E) 
SC : O(N + M) 

Initial Configuration (BFS) : 
1. queue
2. adj vector array store nodes
3. dist array
4. ans vector to store shortest path 

Algorithm : 
1. Make adj List to  store nodes of a graph 

2. dist array[] =
i)  initialize dist array with INT_MAX initlially and 
ii)  assign dist of src as 0 (i.e dist[src] = 0) 
iii) push src in queue 
iv) take queue till it is not empty
a)  front node of queue and explore its neighbour and 
b)  find dist of node 
if(dist[node]+1 < dist[adjnode] )   then update dist[adjnode] = dist[node]+1
c)  push adjnode into queue 

3. create ans vector to store shortest path initialize as -1 vector<int> ans(n,-1)
i) Find shortest path if any node has not assigned distance then return -1 
 if(dist[i] != INT_MAX){
        ans[i]=dist[i];
    }
4. return ans

Implementation 

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
vector<int> adj[n];
for(auto it : edges){
     adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
}

int dist[n];
for(int i=0;i<n;i++){
    dist[i]=INT_MAX;
}
dist[src]=0;

queue<int> q;
q.push(src);

while(!q.empty()){
    int node= q.front();
    q.pop();

    for(auto it:adj[node]){
        if(dist[node]+1 < dist[it]){
            dist[it]=dist[node]+1;
            q.push(it);
        }
    }
}
vector<int> ans(n,-1);
for(int i=0;i<n;i++){
    if(dist[i] != INT_MAX){
        ans[i]=dist[i];
        
    }
    
}
return ans;
}



















