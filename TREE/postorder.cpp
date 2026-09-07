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
    vector<int> postOrder(Node* root) {
        vector<int> a;
        helper(root, a);
        return a;
    }

  private:
    void helper(Node* root, vector<int>& a) {
        if (root == nullptr) return;

        // Traverse left
        helper(root->left, a);

        // Traverse right
        helper(root->right, a);

        // Visit root
        a.push_back(root->data);
    }
};

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \                                                           Postorder Traversal: 4 5 2 3 1

    //    4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<int> result = sol.postOrder(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
