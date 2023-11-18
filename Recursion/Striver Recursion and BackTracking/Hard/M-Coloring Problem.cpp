TC : O(N^M) 
SC : O(N) 

Approach : Start with color 1 if is it is successful then no need to try other options 

class Solution{
public:
bool isSafe(int node,int color[],bool graph[101][101],int col,int n)
{
    for(int i=0;i<n;i++){
        // graph[i][node] means it is adjacent node
    if(i != node && graph[i][node]==1 && color[i]==col){
        return false;
    }
    }
    return true;
}
  bool helper(int node,int color[],bool graph[101][101],int m,int n)
  {
      if(node == n){
          return true;
      }

for(int i=1;i<=m;i++){
    if(isSafe(node,color,graph,i,n)==true){
        color[node] = i;
if(helper(node+1,color,graph,m,n)==true)
{
    return true;
}
else{
    // backtrack
    color[node] = 0;
}
    }
}
return false;
  }
    bool graphColoring(bool graph[101][101], int m, int n) {
int node =0; 
int color[n] = {0};
helper(node,color,graph,m,n);
    }
};
