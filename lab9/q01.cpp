#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBST(TreeNode* node, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (!node) return true;
    if (minNode && node->val <= minNode->val) return false;
    if (maxNode && node->val >= maxNode->val) return false;
    return isBST(node->left, minNode, node) && isBST(node->right, node, maxNode);
}

bool isBalanced(TreeNode* node) {
    if (!node) return true;
    int balanceFactor = height(node->left) - height(node->right);
    if (abs(balanceFactor) > 1) return false;
    return isBalanced(node->left) && isBalanced(node->right);
}

bool isValidAVL(TreeNode* root) {
    return isBST(root) && isBalanced(root);
}
