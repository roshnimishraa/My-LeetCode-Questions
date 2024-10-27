### Approach: Floyd-Warshall Algorithm

Time complexity: 𝑂(𝑛^3)
Space Complexity: 𝑂(𝑛^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));

    for(int i=0;i<n;i++){
        distance[i][i] = 0;
    }
    for(auto &it: edges)
    {
       int u = it[0];
       int v = it[1];
       int wt = it[2];
       distance[u][v] = wt;
       distance[v][u] = wt;
    }
   
//Floyd-Warshall algorithm to find all-pairs shortest path

for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
{
    continue;
}
distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
        }
    }
}

int ans = -1;
int mini = INT_MAX;
for(int i=0;i<n;i++)
{
    int count= 0;
    for(int j=0;j<n;j++)
    {
    if(i != j && distance[i][j] <= distanceThreshold)
    {
            count++;
        }
    }
    if(count <= mini){
        mini = count;
        ans = i ; //node
    }
}
return ans;
    }

};
