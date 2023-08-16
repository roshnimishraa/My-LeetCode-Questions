TC : O(N) 
sc : O(1) 
  
int searchInLinkedList(Node<int> *head, int k) {
Node<int> *curr = head;
    while(curr != NULL){
        if(curr->data == k){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}
