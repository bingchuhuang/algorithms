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


//recursion method, with 1 more arg.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
    int val1 = l1?l1->val:0;
    int val2 = l2?l2->val:0;
    int sum = val1+val2+carry;
    ListNode *result;
    if(l1||l2||carry){    
        result = new ListNode(sum%10);
        int res = sum/10;
        result->next = addTwoNumbers(l1?l1->next:l1,l2?l2->next:l2,res);
    }
    return result;
}

ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    ListNode preNode(0), *p = &preNode;
    int ex = 0;
    while(l1 || l2 || ex){
       int cur = (l1?l1->val:0) + (l2?l2->val:0) + ex;
       ex = cur/10;
       p->next = new ListNode(cur%10);
       p = p->next;
       l1 = l1? l1->next: l1;
       l2 = l2? l2->next: l2;
    }
    return preNode.next;
}

void q2(){
    int ain[2] = {2};
    int bin[2] = {8,9};
    ListNode *a = creatList(2,ain);
    ListNode *b = creatList(2,bin);

    ListNode *c = addTwoNumbers(a,b,0);
    ListNode *d = addTwoNumbers1(a,b);
    printList(c);
    cout<<"method 2:"<<endl;
    printList(d);

}
