class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // In-place
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* l1;
        ListNode* l2;

        if(list1->val <= list2->val){
            l1 = list1;
            l2 = list2;
        }
        else{
            l1 = list2;
            l2 = list1;
        }
        ListNode* head = l1;
        while(l1 != NULL && l2 != NULL){
            ListNode* temp = NULL;
            while(l1 != NULL && (l1->val <= l2->val)){
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            ListNode* t = l1;
            l1 = l2;
            l2 = t;
        }
        return head;



        // Using External Space
        // ListNode* head = NULL;
        // ListNode* tail = NULL;

        // while(list1 != NULL and list2 != NULL){
        //     if(list1->val <= list2->val){
        //         ListNode* newNode = new ListNode(list1->val);
        //         if(head == NULL){
        //             head = newNode;
        //             tail = newNode;
        //         }
        //         else{
        //             tail->next = newNode;
        //             tail = newNode;
        //         }
        //         list1 = list1->next;
        //     }
        //     else{
        //         ListNode* newNode = new ListNode(list2->val);
        //         if(head == NULL){
        //             head = newNode;
        //             tail = newNode;
        //         }
        //         else{
        //             tail->next = newNode;
        //             tail = newNode;
        //         }
        //         list2 = list2->next;

        //     }
        // }
        // while(list1 != NULL){
        //     ListNode* newNode = new ListNode(list1->val);
        //     if(head == NULL){
        //             head = newNode;
        //             tail = newNode;
        //         }
        //         else{
        //             tail->next = newNode;
        //             tail = newNode;
        //         }
        //     list1 = list1->next;
        // }
        // while(list2 != NULL){
        //     ListNode* newNode = new ListNode(list2->val);
        //     if(head == NULL){
        //             head = newNode;
        //             tail = newNode;
        //         }
        //         else{
        //             tail->next = newNode;
        //             tail = newNode;
        //         }
        //     list2 = list2->next;
        // }
        // return head;
    }
};