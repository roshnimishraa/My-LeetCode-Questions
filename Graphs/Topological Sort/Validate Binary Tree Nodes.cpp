class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
    vector<int>& rightChild) 
    {
        vector<vector<int>> graph(n);
        int edge =0;
        
    for(int i=0;i<n;i++)
    {
        if(leftChild[i] != -1)
        {
            graph[i].push_back(leftChild[i]);
            ++edge;
        }
        if(rightChild[i] != -1)
        {
            graph[i].push_back(rightChild[i]);
            ++edge;
        }
    }
        
    //check for self loop and cycle 
        
    queue<int> q;
vector<bool> visited(n,false);
        vector<int> indegree(n,0);
        int counter =0;
        

for(int i=0;i<graph.size();i++){
    for(int j=0;j < graph[i].size();j++){
        indegree[graph[i][j]]++;
    }
}
for(int i=0;i<indegree.size();i++)
{
    if(indegree[i]>1){
        return false;
    }
    if(indegree[i] == 0){
        q.push(i);
        counter++;
    }
}
        
while(!q.empty())
{
    int node = q.front();
    visited[node] = true;
    q.pop();
    
    
for(auto i : graph[node])
{
    indegree[i]--;
    if(!visited[i] && indegree[i] == 0)
    {
        q.push(i);
        counter++;
    }
}
}
 //IF CYCLES ARE PRESENT OR EDGES ARE NOT EQUAL TO N-1 RETURN FALSE 
 if(counter != n || edge != n-1)
 {
     return false;
 }
        return true;
    }
};
