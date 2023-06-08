#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC: O(n)
        if(head == NULL){
            return head;
        }
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* s = d;
        ListNode* f = d;
        for(int i = 0; i < n; i++){
            f = f->next;
        }
        while(f->next != NULL){
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;

        return d->next;


        // TC: O(2n)
        // if(head == NULL){
        //     return head;
        // }
        // int len = 1;
        // ListNode* tail = head;
        // while(tail->next != NULL){
        //     tail = tail->next;
        //     len++;
        // }
        // int k = len - n;
        // if(k == 0){
        //     ListNode* ans = head->next;
        //     // delete(head);
        //     return head->next;
        // }
        // ListNode* prev = head;
        // for(int i = 0; i < k - 1; i++){
        //     prev = prev->next;
        // }
        // ListNode* curr = prev->next;
        // prev->next = curr->next;
        // // delete(curr);

        // return head;
    }
};