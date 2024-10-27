#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(TreeNode* root, int& maxSum) {
    if (!root) return 0;

    int left = max(0, maxProfit(root->left, maxSum));
    int right = max(0, maxProfit(root->right, maxSum));

    int currentMax = left + right + root->val;

    if (currentMax > maxSum) maxSum = currentMax;

    // Return the maximum single path
    return root->val + max(left, right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    int maxSum = -1000000;

    maxProfit(root, maxSum);
    cout << "Maximum Profit Path Sum: " << maxSum << endl;

    return 0;
}
