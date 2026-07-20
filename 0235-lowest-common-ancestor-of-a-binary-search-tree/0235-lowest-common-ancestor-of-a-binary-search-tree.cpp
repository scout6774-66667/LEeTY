class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Tree is empty
        if (root == NULL)
            return NULL;

        // Found p or q
        if (root == p || root == q)
            return root;

        // Search left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Found one node in each subtree
        if (left != NULL && right != NULL)
            return root;

        // Return whichever side found a node
        if (left != NULL)
            return left;

        return right;
    }
};