 Time Complexity: O(N)
Space Complexity: O(N)

// Recursive Approach:

   /*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode *root,vector<int> &ans){
    if(root== NULL) {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void preorder(TreeNode *root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);

}

void postorder(TreeNode *root,vector<int> &ans)
{
    if(root == NULL){
        return;
    }
     postorder(root->left,ans);
     postorder(root->right,ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
  vector<vector<int>> ans;
vector<int>result1,result2,result3;

  inorder(root,result1);
  ans.push_back(result1);

  preorder(root,result2);
  ans.push_back(result2);

 postorder(root,result3);
 ans.push_back(result3);
 
  return ans; 
}
