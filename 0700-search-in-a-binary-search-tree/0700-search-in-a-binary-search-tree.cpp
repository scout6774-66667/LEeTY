class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // Not found
        if (root == NULL)
            return NULL;

        // Found
        if (root->val == val)
            return root;

        // Search left
        if (val < root->val)
            return searchBST(root->left, val);

        // Search right
        return searchBST(root->right, val);
    }
};