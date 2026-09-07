#include <iostream>
#include <vector>
using namespace std;

/* Structure of Tree Node */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> a;
        helper(root, a);
        return a;
    }

  private:
    void helper(Node* root, vector<int>& a) {
        if (root == nullptr) return;

        // Visit root
        a.push_back(root->data);

        // Traverse left
        helper(root->left, a);

        // Traverse right
        helper(root->right, a);
    }
};

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5                                                            Preorder Traversal: 1 2 4 5 3


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.preOrder(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
