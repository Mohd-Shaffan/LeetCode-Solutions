class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *a=head,*b=head->next,*c=head->next->next;
        int first=-1;int last=-1;int mind=INT_MAX;int sidx=-1;int fidx=-1;int i=1;
        if(head->next==nullptr) return {-1,-1};
        while(c){
            if(b->val>a->val && b->val>c->val || b->val<a->val && b->val<c->val ){
                //maxd
                if(first == -1) first = i;
                last=i;
                //mind;
                 fidx = sidx; // Previous critical point index
                 sidx = i;
                if (fidx != -1) {
                    int m = sidx - fidx; // Distance between current and previous critical point
                    mind = min(mind, m); // Update min distance
                }
                 
            }
            i++;
            a=a->next;b=b->next;c=c->next;
        }
        int maxd=last-first;
        if(last==-1 || first==last) return {-1,-1};
        return {mind,maxd};
    }
};