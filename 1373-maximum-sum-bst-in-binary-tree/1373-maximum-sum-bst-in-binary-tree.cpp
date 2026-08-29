class Solution {
public:

    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    Info solve(TreeNode* root) {

        // Empty subtree
        if (root == NULL)
            return {true, INT_MAX, INT_MIN, 0};

        // Get information from left and right
        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check if current subtree is BST
        if (left.isBST &&
            right.isBST &&
            left.maxVal < root->val &&
            root->val < right.minVal) {

            int sum = left.sum + root->val + right.sum;

            // Update maximum answer
            ans = max(ans, sum);

            int minVal = min(left.minVal, root->val);
            int maxVal = max(right.maxVal, root->val);

            return {true, minVal, maxVal, sum};
        }

        // Not a BST
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};