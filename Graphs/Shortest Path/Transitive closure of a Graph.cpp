Approach : Based on Floyd Warshall Algo 

Transitive closure of a graph 
if there is a path reachable from a-> b and 
if there is a path reachable from b-> c 
  that means there is also path exist a-> c

 Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, 
    vector<vector<int>> graph)
    {
       for(int k =0;k<n;k++)
       {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
            if(i==j) {
                graph[i][j] = 1;
            }
if(graph[i][j] ==0)
{
    if(graph[i][k] == 1 && graph[k][j]==1)
    {
        graph[i][j] = 1;
    }
}
               }
           }
       }
       return graph;
    }
};
