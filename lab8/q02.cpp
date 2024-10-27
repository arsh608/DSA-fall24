#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void zigzagTraversal(TreeNode* root) {
    if (!root) return;

    deque<TreeNode*> dq;
    dq.push_back(root);
    bool leftToRight = true;

    while (!dq.empty()) {
        int size = dq.size();  // Number of nodes at the current level
        for (int i = 0; i < size; ++i) {
            if (leftToRight) {
                TreeNode* node = dq.front();
                dq.pop_front();
                cout << node->val << " ";
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            } else {
                TreeNode* node = dq.back();
                dq.pop_back();
                cout << node->val << " ";
                if (node->right) dq.push_front(node->right);
                if (node->left) dq.push_front(node->left);
            }
        }
        cout << endl;
        leftToRight = !leftToRight;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Zigzag Order Traversal:\n";
    zigzagTraversal(root);

    return 0;
}
