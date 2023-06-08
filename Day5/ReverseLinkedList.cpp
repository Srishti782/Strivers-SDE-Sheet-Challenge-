class Solution {
public:
    // Recursive Solution
    // pair<ListNode*, ListNode*> helper(ListNode* head, ListNode* tail){
    //     if(head == tail){
    //         return {head, head};
    //     }
    //     pair<ListNode*, ListNode*> x = helper(head->next, tail);
    //     (x.second)->next = head;
    //     head->next = NULL;
    //     pair<ListNode*, ListNode*> p;
    //     p.first = x.first;
    //     p.second = head;
    //     return p;
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


        // Recursive Solution
        // ListNode* tail = head;
        // while(tail->next != NULL){
        //     tail = tail->next;
        // }

        // pair<ListNode*, ListNode*> p = helper(head, tail);
        // return p.first;
    }
};