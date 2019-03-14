//113. Path Sum II
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        if(!root) return ret;
        subPathSum(root, ret, path, sum);
        return ret;
    }
    void subPathSum(TreeNode* root, vector<vector<int>> &ret,
                                vector<int> &path, int sum) {
        path.push_back(root->val);
        int n = sum-(root->val);
        if(root->left || root->right)
        {
            if(root->left)
                subPathSum(root->left,ret,path,n);
            if(root->right)
                subPathSum(root->right,ret,path,n);
        }
        else if(n == 0)
        {
            ret.push_back(path);
        }
        path.pop_back();
    }
};