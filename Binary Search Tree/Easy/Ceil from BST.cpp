Find : Equal or Smallest number greater than given input

Eg1. input : 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
num = 4
output : 5 

Eg2.  input : 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
num = 5
output : 5 (because 5 is present) 

TC : O(logN) base 2


int findCeil(BinaryTreeNode<int> *node, int x){
 int ceil = -1;
 while(node != NULL){
    // if x present in tree return x as ceil 
    if(x == node->data){
        ceil = node->data;
        return ceil;
    }
    if(x > node->data){
       node = node->right;
    }
    else{
        ceil = node->data;
        node = node->left;
    }
 }
 return ceil;
}
  
