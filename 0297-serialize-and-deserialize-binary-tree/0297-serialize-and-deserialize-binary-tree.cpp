class Codec {
public:

    // Serialize
    void serializeHelper(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }


    // Deserialize
    TreeNode* deserializeHelper(stringstream& ss) {

        string value;
        getline(ss, value, ',');

        if (value == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return deserializeHelper(ss);
    }
};