#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        int c = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + c;
            int d = sum % 10;
            c = sum / 10;
            ListNode* newNode = new ListNode(d);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + c;
            int d = sum % 10;
            c = sum / 10;
            ListNode* newNode = new ListNode(d);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = l2->val + c;
            int d = sum % 10;
            c = sum / 10;
            ListNode* newNode = new ListNode(d);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l2 = l2->next;
        }
        if(c != 0){
            ListNode* newNode = new ListNode(c);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
            return head;

    }
};