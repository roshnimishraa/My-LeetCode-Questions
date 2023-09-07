Same as Course Scheduler - I but 
1. condition of true [0,1] course 0 should be taken before 1 and 
2. return vector 
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
          
        vector<int> adj[V];
        
        vector<int> indegree(V, 0);
        
        // make adjacency list
        
    for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);

        }


 for(int i=0;i<V;i++)
 {
     for(auto it : adj[i]){
      indegree[it]++;
     }
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
        
      vector<int> topo;

        while(!q.empty())
        {
            int u = q.front();
            
            q.pop();
            
            topo.push_back(u);
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
        if(topo.size() == V) 
            return topo;
        
        return {};
    }
};
