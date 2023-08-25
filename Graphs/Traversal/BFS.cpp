TC : O(N) + O(2*E) 
SC : O(3N) ~ O(N) 

Using : 
1. array to store visited array : an array initialized to 0
2. vectore to store bfs traversal 
3. adjacency list 
4. queue to store nodes :  follows FIFO, and will always contain the starting.

Approach : 
1. In BFS, we start with a “starting” node, mark it as visited, and push it into the queue data structure.
2. In every iteration, we pop out the node ‘v’ and put it in the solution vector, as we are traversing this node.
3. All the unvisited adjacent nodes from ‘v’ are visited next and are pushed into the queue. 
  The list of adjacent neighbors of the node can be accessed from the adjacency list.
4. Repeat steps 2 and 3 until the queue becomes empty, and this way you can easily traverse all the nodes in the graph.
