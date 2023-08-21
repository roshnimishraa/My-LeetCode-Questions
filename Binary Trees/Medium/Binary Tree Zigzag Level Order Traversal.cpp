Approach : for even levels we need to go from left to right while for odd levels we need to go from right to left. 

Time Complexity: O(N)   
Space Complexity: O(N)


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
    if(root == NULL) return ans;
        q.push(root);
        int count=0;
    while(!q.empty())
    {
        vector<int>level;
        
int n= q.size();
        for(int i=0;i<n;i++)
        {
    TreeNode *node = q.front();
            q.pop();
            
 
      if(node->left != NULL) 
          q.push(node->left);
            
      if(node->right != NULL)
           q.push(node->right);
            
        level.push_back(node->val);
        }
       if(count%2==1){
                reverse(level.begin(),level.end());
            }
        ans.push_back(level);
        count++;
       
    }
         return ans;
    }
};
