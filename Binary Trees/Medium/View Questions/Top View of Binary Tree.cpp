TC : O(N) 
SC : O(N)

Approach : 
1. First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
2. Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders of keys(Lines).
3. Here we will follow the level order traversal.
4. Traverse through the nodes starting with root,0 and store them to the queue.
5. Until the queue is not empty, store the node  and line no. in 2 separate variable .
6. Then check if that line is present in the map or not
7. If not present then store the line and the node->val to the map
8. Otherwise store the node->left and node->right along with there line nos. to the queue.
9. Then print the node->val from the map


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
      vector<int> ans;
      if(root == NULL)  {
          return ans;
          
      }
      map<int,int> topNode;
      //queue store line and node
      queue<pair<Node *,int>> q;
      
      q.push(make_pair(root,0)); //  q.push({root, 0}); 
      
      while(!q.empty()){
          //take front node value 
         pair<Node*,int> temp = q.front();
              q.pop();
         Node *frontNode = temp.first;
 
         int hd = temp.second;
         
// if one entry is present for HD then ignore others 
if(topNode.find(hd) == topNode.end())
         topNode[hd] = frontNode->data;
         
         if(frontNode->left != NULL)
         //left me -ve hoga horizontal distance
    q.push(make_pair(frontNode->left,hd-1));
    if(frontNode->right != NULL)
    q.push(make_pair(frontNode->right,hd+1));
         
      }
      for(auto i : topNode){
          ans.push_back(i.second);
      }
      return ans;
    }

};
