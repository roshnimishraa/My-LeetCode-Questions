Approach : 

1. Take a queue data structure and push the root node to the queue.
2. Set a while loop which will run till our queue is non-empty.
3. In every iteration, pop out from the front of the queue and assign it to a variable (say temp).
4. If temp has a left child, push it to the queue.
5. If temp has a right child, push it to the queue.
6. At last push the value of the temp node to our “ans” data structure.


TC : theta(N)
SC : O(N) 


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
     queue<TreeNode *> q;
        vector<vector<int>> ans;
       if(root == NULL )  return ans; 
        q.push(root);
        
        while(!q.empty()){
  vector<int> level;
        int n = q.size();
    for(int i=0; i<n;i++){
        //taking node and pop from queue
TreeNode *node = q.front();
        q.pop();
        
    if(node->left != NULL)
        q.push(node->left);
    
       if(node->right != NULL)
           q.push(node->right);
        
    //push into sub vector 
        level.push_back(node->val);
    }
//        push into vector
            ans.push_back(level);
        }
        return ans;
    }
};
