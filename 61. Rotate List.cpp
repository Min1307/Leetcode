//61. Rotate List
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* pr=head;
        ListNode* ur=head;
        int n=1;
        for(;pr->next!=NULL;n++)
            pr=pr->next;
        k=k%n;
        if(k==0) return head;
        for(int i=k;i<n-1;i++)
            ur=ur->next;
        pr->next=head;
        pr=ur->next;
        ur->next=NULL;
        return pr;
    }
};