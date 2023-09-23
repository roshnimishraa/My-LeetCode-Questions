Floyd Warshall Algorithm ~
1. MultiSource Shortest Path 
NOTE : Traverse via every vertex/nodes
2. It helps to detect Negative Cycle 
3. Works for Directed Graph 
>> If undirected graph is given -> Split that edges into two edges of same weight 
An undirected edge between nodes u and v necessarily means thatthere are two opposite-directed edges, one 
  towards node u and the other towards node v. 

Brute Force 
TC : O(N)^3
SC : O(N)^2 for storing adj matrix 

Traverse on all paths using three for loop via traversing through every node to find shortest path 
1. take adj/cost matrix 
2. node to node distance is always 0 and distance from vertex 0 is gets same 
 mark unreachable node as INT_MAX 
mark diagonal (i==j) as 0  
Assign initial cost to node 
3. Make resultant matrix via every node traverse through all the edges
4. For node n traverse -> shortest path matrix found 

for(int via = 0; via < n; via++) {
   for(int i=0; i<n; i++) {
       for(int j=0; j<n; j++) {
           cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]) 
             }
   }
}

Ques) HOW TO DETECT NEGATIVE CYCLE 
if path/cost < 0 then it has -ve cycle but for graph with no cycle the node to node distance is 0 
   
  for(int i=0; i<n; i++) 
{ 
   if(cost[i][i] < 0 ) 
{
     cout<<"Negative cycle exists" ; 
}
}
    

>>>>>>>>>> IMPLEMENTATION 

  //User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<n;j++)
	       {
	       //unreachable node mark INT_MAX
	           if(matrix[i][j]==-1){
	               matrix[i][j]=1e9;
	           }
	       if(i==j) {
	 // diagonal node [0,0],[1,1]..[n,n] cost = 0
	 matrix[i][j] =0;
	  
	       }
	       }
	   }
	   
// 	  compute shortest path via every node
for(int k =0; k<n; k++)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
    // if node has already less value then computed 
    // value then do not update 
    matrix[i][j] = min(matrix[i][j], 
    matrix[i][k] + matrix[k][j]);
        }
    }
}

// 	 if node is not reachable then return -1
 for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<n;j++)
	       {
	       //unreachable node mark INT_MAX
	           if(matrix[i][j]== 1e9){
	               matrix[i][j]= -1;
	           }
	      
	       }
	   }
	}
};
