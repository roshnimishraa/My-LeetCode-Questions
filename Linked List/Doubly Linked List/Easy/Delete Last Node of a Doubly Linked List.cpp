  Time complexity: O(n)
    Space complexity: O(1)

    Corner Case : head == NULL or head->next == NULL

    
Node * deleteLastNode(Node *head) {
Node *curr = head;
if(head == NULL || head->next==NULL){
    return NULL;
}
while(curr->next->next != nullptr){
    curr = curr-> next;
}
Node *nodeToDelete = curr->next;
curr->next =NULL;
delete(nodeToDelete);
return head;
}
