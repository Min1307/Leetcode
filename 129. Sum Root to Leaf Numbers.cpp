//129. Sum Root to Leaf Numbers
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return root->val;
        int sum=0;
        if(root->left) sum += subSumNumbers(root->left, root->val);
        if(root->right) sum += subSumNumbers(root->right, root->val);
        return sum;
    }
    int subSumNumbers(TreeNode* root, int subsum) {
        int n = subsum*10 + root->val;
        if(!root->left&&!root->right) return n;
        int sum=0;
        if(root->left) sum+=subSumNumbers(root->left, n);
        if(root->right) sum+=subSumNumbers(root->right, n);
        return sum;
    }
};