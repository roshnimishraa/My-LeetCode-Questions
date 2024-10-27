### Approach: Disjoint Set 

Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list.
O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times.
Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge
information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function
otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).

class DisjointSet{
  vector<int> parent,size;
  public:
  DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1);
      
      for(int i=0;i<=n;i++)
      {
          parent[i] = i;
          size[i] = 1;
      }
  }
  
//   find path compression
int findUPar(int node){
  if(node == parent[node])   
  return node;
  
  return parent[node] = findUPar(parent[node]);
}

void unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    
    // if they are in same component 
    if(ulp_u == ulp_v) return;
// connect smaller rank to larger rank always
// if they are of equal size then connect any to any node
if(size[ulp_u] < size[ulp_v]){
    parent[ulp_u] = ulp_v;
    size[ulp_v] += size[ulp_u];
}
else{
    parent[ulp_v] = ulp_u;
    size[ulp_u] += size[ulp_v];
}
}
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         // 1 - 2 wt = 5 
         // i.e 1 - (2,5) and 2 - (1,5)
        //  sort w.r.t weight
        // (5,1,2) and (5,2,1)
        // {wt, {node,adjNode}}
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
  edges.push_back({wt,{node, adjNode}});
            }

        }
        
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v))
        {
            mstWt += wt;
            ds.unionBySize(u,v);
        }
        }
        return mstWt;
    }
};
