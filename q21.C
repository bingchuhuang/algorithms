ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode output(-1);
    ListNode *merge = &output;
    while(l1 && l2){
        if(l1->val<l2->val){
            merge->next = l1;
            l1 = l1->next;
        }else{
            merge->next = l2;    
            l2 = l2->next;
        }
        merge = merge->next;
    }
    merge->next = l1?l1:l2;
    return output.next;
}
