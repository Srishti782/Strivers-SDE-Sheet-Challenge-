class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }
//         ListNode* s = head;
//         ListNode* f = head;
//         ListNode* entry = head;
//         while(f->next && f->next->next){
//                 s = s->next;
//                 f = f->next->next;
//             
//             if(s == f){
//             while(s != entry){
//                 s = s->next;
//                 entry = entry->next;
//             }
//             return s;
//             }
//         }
//         return NULL;

        if(head == NULL||head->next == NULL) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* entry = head;
            
        while(fast->next != NULL&&fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
                
            if(slow == fast) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};