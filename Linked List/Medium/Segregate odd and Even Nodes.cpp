TC : O(N) 
SC : O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //corner case 
    if(head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return head;
        
    }
    ListNode *oddPointer =head;
     ListNode *evenPointer = head->next;
    ListNode *startOfEven =head->next;
    
    while(oddPointer->next != NULL && evenPointer->next != NULL)
    {
     oddPointer -> next = evenPointer ->next;   //Connect all odds
        evenPointer -> next = oddPointer->next->next;   //Connect all evens
        
    oddPointer = oddPointer->next;
        evenPointer = evenPointer->next;
        
    }
        
// connect the even pointer to the odd pointer 
          oddPointer->next = startOfEven;
//Place the first even node after the last odd node.
        
        return head;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------

  Segregate Even and Nodes 

  
Node* segregateEvenOdd(Node* head)
{
  Node *oddStart = NULL;
  Node *oddEnd = NULL;
  Node *evenStart = NULL;
  Node *evenEnd = NULL;
  Node *curr = head;

 
  
 while(curr != NULL) {
    int x = curr->data;
    if(x % 2== 0){
      if(evenStart == NULL){
        evenStart = new Node(x);
     //   evenStart = evenEnd = curr;
     evenEnd = evenStart;
      }
      else{
        evenEnd->next = curr;
        evenEnd = evenEnd->next;
      }
    }
    else {
      //odd node 
      if(oddStart == NULL){
    //    remove link from even node
    oddStart = new Node(x);
 oddEnd = oddStart; 
      }
    else{
      oddEnd->next = curr;
      oddEnd = oddEnd->next;
    }
    }
  curr = curr->next;
  }
   //corner case 
//if all nodes are odd OR if all nodes are even 
  if(oddStart != NULL && evenStart != NULL){
evenEnd -> next = oddStart;
oddEnd ->next = NULL;
head = evenStart;
  }
//join the list 

return head;
  
}

  
