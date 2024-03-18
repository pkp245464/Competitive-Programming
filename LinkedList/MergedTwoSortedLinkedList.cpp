// Recursive Method
Node *mergeTwoLinkedList(Node *list1,Node *list2) {
	if(list1==NULL) return list2;
	else if(list2==NULL) return list1;
	Node *ans=NULL;
	
	if(list1->data <= list2->data) {
		ans=list1;
		ans->next=mergeTwoLinkedList(list1->next,list2);
	}
	else {
		ans=list2;
		ans->next=mergeTwoLinkedList(list1,list2->next);
	}
	return ans;
}
//Second Method
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/
/*
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        
        
        if(list1->val > list2->val) swap(list1,list2);
        ListNode *ans=list1;
        
        while(list1!=NULL and list2!=NULL) {
            ListNode *temp=NULL;
            while(list1!=NULL && list1->val <= list2->val) {
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1,list2);
        }
        return ans;
    }
};
*/