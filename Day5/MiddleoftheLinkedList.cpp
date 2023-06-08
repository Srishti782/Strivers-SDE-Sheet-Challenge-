class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        

        // TC: O(n/2) : Tortoise Method
        if((head->next)->next == NULL){
            return head->next;
        }
        ListNode* s = head;
        ListNode* f = head;

        while((f != NULL) && ((f->next) != NULL)){
            s = s->next;
            f = f->next->next;
        }
        return s;

        // TC: O(n + n/2)
        // ListNode* tail = head;
        // int len = 1;
        // while(tail->next != NULL){
        //     tail = tail->next;
        //     len++;
        // }
        // int mid = len / 2;
        // ListNode* ans = head;
        // for(int i = 0; i < mid; i++){
        //     ans = ans->next;
        // }
        // return ans;
    }
};