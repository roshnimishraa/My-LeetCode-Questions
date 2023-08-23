Smallest or equal to greater number than input [val <= key]


int Floor(BinaryTreeNode<int> *node, int input)
{
	
	int floor = -1;
	while(node != NULL){
		if(input == node->data){
			floor = node->data;
			return floor;
		}

		if(input > node->data){
       floor = node->data;
	   node = node->right;
		}
		else{
			node=node->left;
		}
	}
	return floor;
}
