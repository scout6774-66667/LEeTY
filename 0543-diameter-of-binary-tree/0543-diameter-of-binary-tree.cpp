class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Update maximum diameter
        diameter = max(diameter, left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};