BST PROPERTIES
1. Inorder Traversal gives sorted order traversal 
2. For BST element should be in sorted order

Approach : 
1. First sort the nodes
2. Apply inorder traversal recursively or apply any traversal preorder and postorder 

//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
    void helper(Node *root,vector<int> &ans)
    {
        if(root == NULL) return;
        helper(root->left,ans);
        ans.push_back(root->data);
        helper(root->right,ans);
        
    }
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> ans;
      helper(root,ans);
      sort(ans.begin(),ans.end());
      for(auto i : ans){
          cout<<i<<" ";
         
      }
      
       return NULL;
    }
};
