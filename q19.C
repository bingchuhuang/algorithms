struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};


ListNode *creatList(int n, int *in) {
    ListNode head(-1);
    ListNode *prev = &head;
    ListNode *prev2;
    prev2 = &head;
    int val;

    for (int i = 0; i < n; ++i) {
        val = in[i];
        //allocate the memory space for new node
        prev->next = new ListNode(val); 
        prev = prev->next;
    }
    prev->next = NULL;
    return head.next;
}

void printList(ListNode *l){
    ListNode *nt = l;
    while(nt){
        cout<<nt->val<<endl;
        nt = nt->next;
    }
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow=head,*fast=head;
    int dis = 1;
    while(fast->next!=NULL){
        fast = fast->next;
        if(dis>n) slow = slow->next;
        dis++;
    }
    if(dis<n) return NULL;
    if(dis==n){
        head = slow->next;
        delete slow;
    }else{
        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;
        delete to_be_deleted;
    }
    return head;
}

void q19(){
    int ain[7] = {1,2,3,4,5,6,7};
    //int ain[2] = {1,2};
    ListNode *a = creatList(2,ain);
    //printList(a);
    ListNode *c = removeNthFromEnd(a,2);
    printList(c);
}
