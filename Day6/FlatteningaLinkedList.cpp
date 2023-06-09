Node* mergeTwoLists(Node* list1, Node* list2) {
        // In-place
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        Node* l1;
        Node* l2;

        if(list1->data <= list2->data){
            l1 = list1;
            l2 = list2;
        }
        else{
            l1 = list2;
            l2 = list1;
        }
        Node* head = l1;
        while(l1 != NULL && l2 != NULL){
            Node* temp = NULL;
            while(l1 != NULL && (l1->data <= l2->data)){
                temp = l1;
                l1 = l1->bottom;
            }
            temp->bottom = l2;
            Node* t = l1;
            l1 = l2;
            l2 = t;
        }
        return head;
    }
Node *flatten(Node *head)
{
   // Your code here
   if(head == NULL){
		return NULL;
	}
	Node* temp = flatten(head->next);
	return mergeTwoLists(head, temp);
}