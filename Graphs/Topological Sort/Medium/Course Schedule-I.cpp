Logic: Detect cycle in directed graph using BFS BUT return true
  if there is no cycle as there is no dependency between nodes
return false if count < N that means there is cycle 

Eg. Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

  Eg. numCourses = 4, prerequisites = [[1,2],[4,3],[2,4],[4,1]] 
  output : false (There is cycle therefore dependency between nodes)
  
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).

class Solution {
public:
    bool canFinish(int N,  vector<vector<int>>& prerequisites)
    {
        vector<int> adj[N];
    for(auto it:prerequisites)
    {
   
   adj[it[0]].push_back(it[1]);
    }
// kahn's algo 
vector<int> indegree(N,0);
for(int i=0;i<N;i++)
{
    for(auto it:adj[i])
    {
    indegree[it]++;
    }
}
queue<int> q;
for(int i=0;i<N;i++)
{
    if(indegree[i]==0){
q.push(i);
    }
}

int count=0;
while(!q.empty()){
    auto node = q.front();
    q.pop();
count++;
for(auto it:adj[node])
{
    indegree[it]--;
    if(indegree[it]==0)
    {
        q.push(it);
    }
}
}
if(count == N) return true;
return false;
    }
};
