// Merge two sorted LL;
node *merge(node *&head1, node *&head2){
    *p1 = head1;
    *p2  = head2;
    *dummynode = new node(-1)
    *p3  =dummynode;
    while (p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data){
            p3->next =  p1;
            p1= p1->next;
        }
        else{
            p1->next = p2;
            p2 = p2->next
        }
        p3 = p3->next
    }
    
    while (p1!=NULL)
    {
        p3->next = p1
        p3 = p3->next
        p1= p1->next;
    }
    while(p2!=NULL){
        p3->next = p2
        p3 = p3->next
        p2= p2->next;
    }
    return dummynode->next // new head
    
}

// Recursive approach for merging
 Node *merge(*&head1, *&head2){
     if(head1==NULL){
         return head2;
     }
     if(head2==NULL){
         return head1;
     }
     node *res;
     if(head1->data<head2->data){
         res = head1;
         res->next = merge(head1->next,head2)
     }
     else{
         res = head2;
         res->next = merge(head1,head2->next)
     }
     return res; // head after each recursive call
 }

 // put even position nodes after odd position nodes
 // two pointers 1) odd 2) even

 node * put(*&head){
     *odd = head
     *even = head->next
     evenstart = even  // to link last node of odd to even
     while(odd->next!=NULL && even->next!=NULL){
         odd->next = even->next;
         odd = odd->next;
         even->next = odd
         even->next = odd->next
         even = even->next
     }
        if(odd->next!=NULL){
            even->next  = NULL
        }
        odd->next=evenstart
 }

