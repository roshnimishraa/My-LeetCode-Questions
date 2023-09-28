TC : O(N LOG N) 
SC : O(N) 
  
class Node{
    public: 
     int data;
     Node *left;
     Node *right;
     
     Node(int d)
     {
         data = d;
         left = NULL;
         right= NULL;
     }
};

//  comparator
class cmp 
{
    public:
    bool operator()(Node *a,Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    
	public:
	void preOderTraverse(Node *root,vector<string> &ans,
	string temp)
	{
	    //base
	    if(root->left == NULL && root->right == NULL)
	    {
	        ans.push_back(temp);
	        return;
	    }
	    
	  preOderTraverse(root->left,ans,temp+'0');
	    preOderTraverse(root->right,ans,temp+'1');
	}
	
		vector<string> huffmanCodes(string S,vector<int> f,
		int n)
		{
 priority_queue<Node*,vector<Node*>,cmp> pq;
 for(int i=0;i<n;i++)
 {
     Node* temp = new Node(f[i]);
     pq.push(temp);
     
 }
 
 while(pq.size() > 1)
 {
     Node *left = pq.top();
     pq.pop();
     Node *right = pq.top();
     pq.pop();
     
     Node* newNode= new Node(left->data + right->data);
     newNode->left =left;
     newNode->right = right;
     
     pq.push(newNode);
 }
//  single node left 
 Node *root = pq.top();
 
//  proder traversal to store the encoding 
vector<string> ans;
string temp="";
preOderTraverse(root,ans,temp);
return ans;
}
};
