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
    void dfs(Node* ans, Node* node, unordered_map<Node*, Node*>&m)
    {
        m[node] = ans;
        for(auto it: node->neighbors)
        {
            if(!m.count(it))
            {
                Node *value = new Node(it->val);
                ans->neighbors.push_back(value);
                dfs(value, it, m);
            }
            else ans->neighbors.push_back(m[it]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* ans = new Node(node->val);
        unordered_map<Node*, Node*>m;
        dfs(ans, node, m);
        return ans;
    }
};