class Solution {
public:
    // bool helper(ListNode* head, int len){
    //     if(len <= 1){
    //         return true;
    //     }
    //     ListNode* temp = head;
    //     for(int i = 1; i < len; i++){
    //         temp = temp->next;
    //     }
    //     if(head->val != temp->val){
    //         return false;
    //     }
    //     return helper(head->next, len - 2);
    // }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Iterative solution
        ListNode* d = NULL;
        ListNode* next = head->next;
        while(head != NULL){
            next = head->next;
            head->next = d;
            d = head;
            head = next;
        }
        return d;
    }

    bool isPalindrome(ListNode* head) {
        // Optimal Approach, TC: O(3* n / 2), SC:O(1)
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* s = head;
        ListNode* f = head;

        while(f->next != NULL && f->next->next != NULL){
            s = s->next;
            f = f->next->next;
        }
        s->next = reverseList(s->next);
        s = s->next;
        ListNode* temp = head;
        while(s != NULL){
            if(temp->val != s->val){
                return false;
            }
            s = s->next;
            temp = temp->next;
        }
        return true;

        // Brute Force, TC: O(2*n), SC: O(n)
        // if(head == NULL || head->next == NULL){
        //     return true;
        // }
        // map<int, ListNode*> mp;
        // ListNode* tail = head;
        // int len = 1;
        // while(tail != NULL){
        //     mp[len] = tail;
        //     len++;
        //     tail = tail->next;
        // }
        // len--;
        // for(int i = 1; i <= len / 2; i++){
        //     if((mp[i]->val) != (mp[len - i + 1]->val)){
        //         return false;
        //     }
        // }
        // return true;


        // Recursive Solution: TC: O(n^2)
        // if(head == NULL || head->next == NULL){
        //     return true;
        // }
        // ListNode* tail = head;
        // int len = 1;
        // while(tail->next != NULL){
        //     len++;
        //     tail = tail->next;
        // }
        // return helper(head, len);
    }
};