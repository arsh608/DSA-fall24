#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode23 {
    vector<int> keys;  // Keys at a node
    vector<TreeNode23*> children; // Children
};

void levelOrderTraversal(TreeNode23* root) {
    if (!root) return;
    queue<TreeNode23*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode23* node = q.front();
            q.pop();
            for (int key : node->keys) cout << key << " ";
            for (auto child : node->children) {
                if (child) q.push(child);
            }
        }
        cout << endl;
    }
}
