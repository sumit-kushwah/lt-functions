//
// Created by sumit Kushwah on 23/02/22.
//

// currently, two methods in my mind
// 1.using recursion solve the problem
// 2.using hashmap convert each node into new node

#include <bits/stdc++.h>
using namespace std;

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

unordered_map<int, int> m;
void printGraph(Node* graph) {
    if(graph == NULL) return;
    int value = graph->val;
    m[value] = 1;
    vector<int> v;
    for (auto & node: graph->neighbors) {
        if (!m[node->val]) {
            v.push_back(node->val);
            printGraph(node);
        } else {
            v.push_back(node->val);
        }
    }
    printf("%d  %p: ", value, graph);
    for (int e: v) {
        cout << e << " ";
    }
    cout << endl;
}

unordered_map<int, Node*> umap;
unordered_map<int, int> visited;
Node* cloneGraph(Node* node) {
    if (node == nullptr) return node;
    Node* ans = new Node(node->val);
    visited[node->val] = 1;
    umap[node->val] = ans;
    for (auto & n: node->neighbors) {
        if (visited[n->val] == 0) {
            Node* temp = cloneGraph(n);
            ans->neighbors.push_back(temp);
        } else {
            ans->neighbors.push_back(umap[n->val]);
        }
    }
    return ans;
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    first->neighbors = {second, fourth};
    second->neighbors = {first, third};
    third->neighbors = {second, fourth};
    fourth->neighbors = {first, third};
    printGraph(first);
    Node* temp = cloneGraph(first);
    printGraph(temp);
    return 0;
}
