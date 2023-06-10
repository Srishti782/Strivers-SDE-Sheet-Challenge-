class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* newhead = NULL;
        Node* tail = NULL;
        Node* temp = head;

        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            if(newhead == NULL){
                newhead = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            temp = temp->next;
        }

        temp = head;
        Node* newtemp = newhead;
        while(temp != NULL){
            if(temp->random != NULL){
                Node* target = temp->random;
                Node* t = head;
                int l = 1;
                while(t != target){
                    l++;
                    t = t->next;
                }
                Node* newt = newhead;
                for(int i = 1; i < l; i++){
                    newt = newt->next;
                }
                newtemp->random = newt;
            }
            temp = temp->next;
            newtemp = newtemp->next;
            
        }


        return newhead;
    }
};