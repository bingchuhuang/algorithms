#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

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

void printList(vector<ListNode*> l){
    vector<ListNode*>::iterator it;
    int i=0;
    for(it=l.begin();it!=l.end();++it){
        cout<<"printing list "<<i<<endl;
        i++;
        ListNode *nt = *it;
        printList(nt);
    }
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == nullptr){
        return l2;
    }
    if(l2 == nullptr){
        return l1;
    }
    if(l1->val <= l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}


ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        std::cout<<"0____"<<std::endl;
        printList(lists);
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        std::cout<<"1____"<<std::endl;
        printList(lists);
        lists.erase(lists.begin());
        std::cout<<"2____"<<std::endl;
        printList(lists);
        lists.erase(lists.begin());
        std::cout<<"3____"<<std::endl;
        printList(lists);
    }
    return lists.front();
}

//heap solution
static bool heapComp(ListNode* a, ListNode* b) {
    return a->val > b->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp); 
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}

void q23(){
    const int nA = 4;
    const int nB = 4;
    const int nC = 3;
    int a[nA] = {1,3,4,8};
    int b[nB] = {2,5,7,11};
    int c[nC] = {6,9,10};
    ListNode *la = creatList(nA,a);
    ListNode *lb = creatList(nB,b);
    ListNode *lc = creatList(nC,c);

    vector<ListNode*> lists;
    lists.push_back(la);
    lists.push_back(lb);
    lists.push_back(lc);

    mergeKLists(lists);

}
