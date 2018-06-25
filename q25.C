ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dum(-1);
    ListNode *prev = &dum;
    prev->next = head;
    ListNode *ref = prev;
    while(prev->next){
        vector<ListNode *> nodes(k);
        for(int i=0;i<k;i++){
            if(!prev->next) return dum.next;
            nodes[i] = prev->next;
            prev = prev->next;
        }
        ListNode *post = nodes[k-1]->next;
        for(int i=k-1;i>0;i--){
            nodes[i]->next = nodes[i-1];
        }
        nodes[0]->next = post;
        ref->next = nodes[k-1];
        ref = nodes[0];
        prev = nodes[0];
    }
    return dum.next;
}
void q25(){

}
