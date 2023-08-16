    Time Complexity: O( n ) 
    Space Complexity: O( n )

Node* constructDLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *temp= head;
    int n= arr.size();
    for(int i=1;i<n;i++){
        Node* currNode = new Node(arr[i]);
        temp->next = currNode;
        currNode->prev = temp;
        temp = temp->next;
    }
return head;
}
