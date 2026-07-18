class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both are empty
        if (left == NULL && right == NULL)
            return true;

        // One is empty
        if (left == NULL || right == NULL)
            return false;

        // Values are different
        if (left->val != right->val)
            return false;

        // Compare mirror children
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};