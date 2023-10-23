Approach : Level Order Traversal + queue + map 
1. Take a queue of pair store node and horizontal distance 
make a straight line from root their hd = 0 if overlapping node print smaller first then other 
hd = -2 -1 0 1 2 
2. Take a map to store (hd,node) store in sorted order with respect to horizontal distance 
3. do level order traversal 
a) traverse through starting nodes as root, and store it in queue
b) until the queue is not empty store the node and hd
c) if the hd is present in the map or not 
i) if present that means there mapping(top view ) is already present store the node->left and node->right along with there hd to the queue
ii) If not present then store the hd and the node->val to the map
4. print the node->val from the map

TC : O(N) 
SC : O(N) 

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
  vector<int> ans;
  if(root == NULL) {
      return ans;
  }
  //store (hd,node) in map
 map<int ,int > mp;
 //store (node,hd) in queue 
 queue<pair<Node*,int>> q;
 q.push({root,0});
 while(!q.empty()){
     auto it = q.front();
     q.pop();
  Node* node = it.first;
     int hd = it.second;
    
//if in map one value is present for a hd then do nothing
// if node does not exist in map
if(mp.find(hd) == mp.end()){
// add hd and node in map 
mp[hd] = node->data;
}

if(node->left != NULL){
    q.push({node->left,hd-1});
}
if(node->right != NULL) {
    q.push({node->right,hd+1});
}
 }
 //take ans from map 
 for(auto i : mp){
// i-> ({node,hd}) -> I want node
ans.push_back(i.second);
 }
 return ans;
    }

};
