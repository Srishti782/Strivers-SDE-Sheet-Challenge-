class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute Force: TC: O(m*n), SC: O(1)
        // if(headA == NULL || headB == NULL){
        //     return NULL;
        // }
        // ListNode* l1 = headA;
        // ListNode* l2 = headB;
        // ListNode* prev1, prev2;
        // while(l1 != NULL){
        //     l2 = headB;
        //     while(l2 != NULL){
        //         if((l1->val == l2->val) && (l1->next == l2->next) && (l1 == l2)){
        //             return l1;
        //         }
        //         l2 = l2->next;
        //     }
        //     l1 = l1->next;
        // }
        // return NULL;


        // better approach: TC: O(m + n), SC: O(m + n)
        // if(headA == NULL || headB == NULL){
        //     return NULL;
        // }
        // ListNode* l1 = headA;
        // ListNode* l2 = headB;
        // unordered_map<ListNode*, int> mp;
        // while(l1 != NULL){
        //     mp[l1]++;
        //     l1 = l1->next;
        // }
        // while(l2 != NULL){
        //     mp[l2]++;
        //     if(mp[l2] == 2){
        //         return l2;
        //     }
        //     l2 = l2->next;
        // }

        // return NULL;

        // Optimal Approach 1, TC: O(2 * max(m,n))

        // if(headA == NULL || headB == NULL){
        //     return NULL;
        // }
        // ListNode* l1 = headA;
        // ListNode* l2 = headB;
        // int m = 1, n = 1;
        // while(l1->next != NULL && l2->next !=NULL){
        //     m++;
        //     n++;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // while(l1->next != NULL){
        //     m++;
        //     l1 = l1->next;
        // }
        // while(l2->next != NULL){
        //     n++;
        //     l2 = l2->next;
        // }
        // int k = abs(m - n);
        // l1 = headA;
        // l2 = headB;
        // if(m >= n){
        //     while(k--){
        //         l1 = l1->next;
        //     }
        // }
        // else{
        //     while(k--){
        //         l2 = l2->next;
        //     }
        // }
        // while(l1 != NULL && l2 != NULL){
            // if((l1 == l2) && (l1->val == l2->val) && (l1->next == l2->next)){
            //     return l1;
            // }
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // return NULL;

        // Second best optimal approach: TC: O(2* max(m,n))

        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1 != l2){
            if(l1 == NULL){
                l1 = headB;
            }
            else if(l2 == NULL){
                l2 = headA;
            }
            else{
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return l1;

    }
};