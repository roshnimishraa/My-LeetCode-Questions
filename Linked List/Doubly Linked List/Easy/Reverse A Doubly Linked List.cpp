Iterative Approach : 
Time Complexity: O(N)
Space Complexity: O(1)

Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next== NULL){
        return head;
    }
    Node *curr = head;
    Node *prev =NULL;
    while(curr != NULL){
      Node *next = curr -> next;
       curr->next = prev;
       curr->prev = next;
       prev = curr;
       curr = next;

    }
    return prev;
}

Recursive Approach : 
TC : O(N) 
SC : O(N)

Node* reverseDLL(Node* head)
{   
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursive calls
    Node * temp = reverseDLL(head->next);
    
    temp->prev = NULL;
    head->next->next = head;
    head->prev = head->next ;
    head->next = NULL;
    
    return temp;
}
