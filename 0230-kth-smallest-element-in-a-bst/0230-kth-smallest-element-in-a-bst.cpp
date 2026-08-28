class Solution {
public:
    int count = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if (root == NULL)
            return;

        // Left
        inorder(root->left, k);

        // Root
        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        // Right
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};