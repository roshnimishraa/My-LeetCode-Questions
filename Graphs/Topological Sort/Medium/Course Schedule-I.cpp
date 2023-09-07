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
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[V];
        
        vector<int> indegree(V, 0);
        
        // make adjacency list
        
        // find the indegree of every vertexes
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            
            // update indegree
            
            indegree[u]++;
        }
        
        // push all the vertices with indegree == 0, into queue
        
        queue<int> q;
        
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int count = 0;
        

        while(!q.empty())
        {
            int u = q.front();
            
            q.pop();
            
            count++;
            
            // for every adjacent of u, decrement the indegree
            
            for(auto v : adj[u])
            {
                indegree[v]--;
                
                // if indegree becomes 0, then push into queue
                
                if(indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
 //there is no cycle that's means no dependency       
        if(count == V) 
            return true;
        
        return false;
    }
};
