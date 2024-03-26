/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> found;

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        Node* newNode = new Node;
        newNode->val = node->val;
        if (found.count(node->val) == 0) {
            found[node->val] = newNode;
        }

        for (int i = 0; i < node->neighbors.size(); ++i) {
            if (found.count(node->neighbors[i]->val)) {
                newNode->neighbors.push_back(found[node->neighbors[i]->val]);
            } else {
                newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }

        return newNode;
    }
};