
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=head;
        ListNode* Next=head->next;
        while(Next){
            while(Next && prev->val==Next->val){
                Next=Next->next;
            }
            prev->next=Next;
            prev=Next;
            if(Next) Next=Next->next;


        }
        return head;
    }
};