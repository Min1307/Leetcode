//92. Reverse Linked List II
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode* prehead = new ListNode(0);
        prehead->next = head;
        ListNode* pre = prehead;
        for(int i=1; i<m; i++)
            pre = pre->next;    
        ListNode* last = pre->next;
        ListNode* ptr = last;
        for(int i=m; i<n; i++)
        {
            pre->next = ptr->next;
            ptr->next = pre->next->next;
            pre->next->next = last;
            last = pre->next;
        }
        return prehead->next;
    }
};