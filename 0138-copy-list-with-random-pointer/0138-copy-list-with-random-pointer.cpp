class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* dummy=new Node(0);
        Node* tempC=head;
        Node* tempD=dummy;
        while(tempC){
            Node* a=new Node(tempC->val);
            tempD->next=a;
            tempD=tempD->next;
            tempC=tempC->next;
        }
        Node* a=head;
        Node* b=dummy->next;
        unordered_map<Node*,Node*> mp;
        Node* tempa=head;
        Node* tempb=dummy->next;

        while(tempa){
            mp[tempa]=tempb;
            tempa=tempa->next;
            tempb=tempb->next;
        }
        for(auto x:mp){
            Node* o=x.first;Node* d=x.second;
            if(o->random){
                Node* DupRan=(mp[o->random]);
                d->random=DupRan;
            }

        }
        return b;

        
    }
};