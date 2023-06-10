class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Optimal Approach, TC: O(n), SC: O(1)
        if(head == NULL || head->next == NULL){
            return head;
        }
        if(k == 0){
            return head;
        }
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        if(k > len){
            while(k > len){
                k = k - len;
            }
        }
        if(k == len){
            return head;
        }
        ListNode* prev = head;
        for(int i = 1; i < len - k; i++){
            prev = prev->next;
        }
        tail->next = head;
        head = prev->next;
        prev->next = NULL;
        return head;



        // Brute Force(Recursion), TC: O(k*n), SC: O(1)
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }
        // if(k == 0){
        //     return head;
        // }
        // ListNode* prev = head;
        // while(prev->next->next != NULL){
        //     prev = prev->next;
        // }
        // ListNode* tail = prev->next;
        // tail->next = head;
        // prev->next = NULL;
        // head = tail;
        // return rotateRight(head, k - 1);

    }
};