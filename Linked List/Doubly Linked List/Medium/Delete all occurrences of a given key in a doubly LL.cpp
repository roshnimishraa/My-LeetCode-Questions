TASK : Delete all the nodes having data equal to k

TC : o(N)
SC : O(1)

Node * deleteAllOccurrences(Node* head, int k) {
     if(head == NULL) return head;
    
Node *curr =head;

while(curr != NULL){
     if(curr->data == k){
          Node *curr2 = curr;
          if(curr->prev != NULL)
              curr->prev->next = curr->next;
 
          if(curr->next != NULL)
              curr->next->prev = curr->prev;
        
          if(curr == head)
      
            head = head-> next;
            curr = curr->next;
            delete curr2;
            
     
     }
     
     else 
     curr=curr->next;
}
return head;
}
