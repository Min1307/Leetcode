//106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* create(vector<int>& inorder, vector<int>& postorder, int ps, int pe, int is, int ie){
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[ie]);
        int pos = ps;
        for(; pos <= pe && inorder[pos] != node->val; pos++);
        node->left = create(inorder, postorder, ps, pos-1, is, is+pos-ps-1);
        node->right = create(inorder, postorder, pos+1, pe, is+pos-ps, ie-1);
        return node;
    }
};