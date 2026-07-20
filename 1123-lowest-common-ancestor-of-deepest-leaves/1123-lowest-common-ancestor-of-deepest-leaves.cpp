class Solution {
public:

    // Function to find height of a tree
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        if (root == NULL)
            return NULL;

        int left = height(root->left);
        int right = height(root->right);

        if (left > right)
            return lcaDeepestLeaves(root->left);

        if (right > left)
            return lcaDeepestLeaves(root->right);

        return root;
    }
};