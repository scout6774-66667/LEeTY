class BSTIterator {
public:

    stack<TreeNode*> st;

    // Push all left nodes
    void pushLeft(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // Process right subtree
        pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};