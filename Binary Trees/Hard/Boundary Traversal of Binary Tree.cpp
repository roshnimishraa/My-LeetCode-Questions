TC : O(N) 
SC : O(H) 

Approach :
1. Store left subtree nodes in vector array excluding leaf nodes
2. store leaf nodes from left subtree to right subtree 
     then searching for left and right for leaf nodes
3. store right subtree nodes in reverse(store root at last ) 


void traverseLeft(TreeNode<int> *root, vector<int> &ans)
{
    //base case 
 if(root == NULL)  return;

 //exclude leaf node
 if(root->left == NULL && root->right == NULL)
 return;

 // insert root 
 ans.push_back(root->data);

 //print root->left 
 if(root->left != NULL){
     traverseLeft(root->left,ans);

 }
 else{
     traverseLeft(root->right,ans);
 }
}

void traverseLeaf(TreeNode<int> *root, vector<int> &ans)
{
    //base case 
    if(root== NULL) return;

if(root->left == NULL && root->right == NULL)
{
    ans.push_back(root->data);
    return;
}

// move left and right 
traverseLeaf(root->left,ans);
traverseLeaf(root->right,ans);
}

void traverseRight(TreeNode<int> *root,vector<int> &ans)
{
 //base case 
 if(root == NULL) return;

 //exclude leaf node 
 if(root->left == NULL && root->right == NULL){
     return;
 }

 //print right 
 if(root->right != NULL){
     traverseRight(root->right,ans);

 }
 else{
     traverseRight(root->left,ans);
 }

 //reverse ans print 
 ans.push_back(root->data);
 
}


vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(root == NULL)  return ans;

 //1. print root 
 ans.push_back(root->data);

 //2. left part print/store
 traverseLeft(root->left,ans);

 //3. Traverse Leaf nodes 
 //leaf node can be in leaf subtree and right subtree 
 //left subtree nodes
 traverseLeaf(root->left,ans);

 //right subtree leaf nodes
 traverseLeaf(root->right,ans);

 //4. right subtree 
traverseRight(root->right,ans);
return ans;
}
