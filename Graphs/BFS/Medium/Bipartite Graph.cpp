NOTE :
1. Bipartite Graph :- Color the graph with 2 colors such that NO Adjacent nodes have same color. 
2. Linear Grpahs with NO CYCLE are always Bipartite Graph 
3. Any graph with even cycle length can also be Bipartite Graph
4. Any graph with odd length cycle can never be Bipartite Graph

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one 
and a node in the other.


class Solution {
    private:
    bool check(int  start,int V,vector<int> adj[],int col[])
    {
        	  queue<int> q;
	  q.push(start);
	 col[start]=0;
while(!q.empty())
{
    int node=q.front();
    q.pop();
    
    for(auto it : adj[node])
    {
        if(col[it]==-1)
        {
            col[it]= !col[node];
            q.push(it);
            
        }
        else if(col[it] == col[node]){
            // if already colored
            return false;
        }
    }
}
      
return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	 int color[V];
	for(int i=0;i<V;i++)
	{
	   color[i]=-1;
	}
	
for(int i=0;i<V;i++)
{
    if(color[i]==-1)
    {
        if(check(i,V,adj,color) == false){
            //not bipartite
            return false;
        }
    }
}
return true;
	}
};

