//117. Populating Next Right Pointers in Each Node II
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node *ro = root;
        Node * pre = new Node(0);
        pre->next = nullptr;
        Node * re = pre;
        while(root)
        {
            if(root->left)
            {
                pre->next = root->left;
                pre = pre->next;
            }
            if(root->right)
            {
                pre->next = root->right;
                pre = pre->next;
            }
            root = root->next;
            if(!root)
            {
                pre = re;
                root = re->next;
                re->next = nullptr;
            }
        }
        return ro;
    }
};