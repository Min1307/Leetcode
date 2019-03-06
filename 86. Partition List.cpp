//86. Partition List
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode l(0),h(0);
        ListNode* l1=&l,* h1=&l;
        ListNode* l2=&h,* h2=&h;
        while(head)
        {
            if(head->val < x)
            {
                l1->next = head;  
                l1 = head;
            }
            else
            {
                l2->next = head;
                l2 = head;
            }
            head = head->next;
        }
        l2->next = NULL;
        l1->next = h2->next;
        return h1->next;
    }
};