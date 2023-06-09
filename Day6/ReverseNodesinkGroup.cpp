class Solution {
public:
    ListNode* helper(ListNode* head, int k, int len){
        if(len < k){
            return head;
        }
        ListNode* h = head;
        for(int i = 1; i <= k; i++){
            h = h->next;
        }
        ListNode* x = helper(h, k, len - k);
        ListNode* temp = x;
        ListNode* next = head;
        while(next != h){
            next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }
        return helper(head, k, len);
        
    }
};