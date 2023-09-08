Approach : DFS

Given : Adj List 

Approach 
1. Do DFS traversal mark visited that means they are reachable 
2. if nodes are visited return true else return false
  
>>>>Time complexity:
O(n)
>>>>Space complexity:
O(2n) ~ O(n)

class Solution {  
   public:
 void dfs(int node,vector<vector<int>>& rooms,vector<int> &vis)
    {
        vis[node]=1;
for(auto it : rooms[node])
    if(vis[it]==0)
        dfs(it,rooms,vis);
  
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       
    int n=rooms.size();
     vector<int> vis(n,0);
dfs(0,rooms,vis);
for(auto it:vis){
    if(it==0) return false;
}
return true;
    }
};


###################################################################################################################################################################################
Approach : BFS

  /* Time complexity:
O(n)

Space complexity:
O(2n) ~ O(n)*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     queue<int> q;
     int n=rooms.size();
     vector<int> vis(n,0);
    q.push(0);
    while(!q.empty())
    {
int curr_room = q.front();
q.pop();

vis[curr_room] = 1;

for(auto key : rooms[curr_room]){
    if(!vis[key]){
        q.push(key);
    }
}
    }
for(int i=0;i<n;i++)

    if(vis[i] == 0) return false;

       
return true;
    }
};
