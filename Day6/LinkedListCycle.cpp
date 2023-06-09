class Solution {
public:
    bool hasCycle(ListNode *head) {
        // TC: O(n), SC: O(n)
        // if(head == NULL){
        //     return false;
        // }
        // map<ListNode*, int> mp;
        // ListNode* l = head;
        // while(l != NULL){
        //     mp[l]++;
        //     l = l->next;
        //     if(mp[l] == 2){
        //         return true;
        //     }
        // }
        // return false;
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* s = head;
        ListNode* f = head;
        while(s != NULL && f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
            if(s == f){
                return true;
            }
        }
        return false;
    }
};