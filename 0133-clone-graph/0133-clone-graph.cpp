class Solution {
public:
     unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        if(cloned.count(node)){
            return cloned[node];
        }
        Node* copy = new Node(node->val);
        cloned[node] = copy;
        for(auto neighbour : node->neighbors){
            copy->neighbors.push_back(cloneGraph(neighbour));
        }

        return copy;
    }
};