Approach : Level Order Traversal + queue + map 
1. Take a queue of pair store node and horizontal distance 
2. Take a map to store (hd,node) store in sorted order with respect to horizontal distance 
3. do level order traversal 
a) traverse through starting nodes as root, and store it in queue
b) until the queue is not empty store the node and hd
c) if the hd is present in the map or not 
i) if present store the node->left and node->right along with there hd to the queue
ii) If not present then store the hd and the node->val to the map
4. print the node->val from the map

TC : O(N) 
SC : O(N) 

