ListNode* swapPairs(ListNode* head) {
    ListNode *p,*q;
    ListNode dum(-1);
    ListNode *out = &dum;
    out->next = head;
    while(head){
        p = head;
        q = head->next;
        if(!p||!q){
            break;
        }
        ListNode *tmp = head->next->next;
        out->next = q;
        q->next = p;
        p->next = tmp;
        out = p;
        head = tmp;
    }
    return dum.next;
}
