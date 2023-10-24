Approach : BFS 
  
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
if(root == NULL) {
    return {};
}
            vector<int> ans;
    while(!q.empty()){
        //current level size 
int n = q.size();
    //for every level 
    int maxEle = INT_MIN;
        while(n--){
          TreeNode* node = q.front();
            q.pop();
            
            maxEle = max(maxEle,node->val);
    if(node->left != NULL) {
        q.push(node->left);
    }
if(node->right != NULL) {
    q.push(node->right);
}
}
          ans.push_back(maxEle);
    } 
      
    return ans;
    }
};
