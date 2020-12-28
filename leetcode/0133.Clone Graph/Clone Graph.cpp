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
    Node* used[101];
    
    Node* cloneGraph(Node* node) 
    {
        if(!node) return node;
        if(used[node->val])
        {
            return used[node->val];
        }

        Node* root = new Node(node->val);
        used[node->val] = root;
        int n = node->neighbors.size();
        for(int i=0;i<n;i++)
        {
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
    }
};
