#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode23 {
    vector<int> keys;               // Keys(1 or 2)
    vector<TreeNode23*> children;   // Children (2 or 3)
    bool isLeaf;

    TreeNode23(bool leaf = true) : isLeaf(leaf) {}
};

void levelOrderTraversal(TreeNode23* root) {
    if (!root) return;
    vector<TreeNode23*> currentLevel = {root};

    while (!currentLevel.empty()) {
        vector<TreeNode23*> nextLevel;
        for (TreeNode23* node : currentLevel) {
            for (int key : node->keys) cout << key << " ";
            cout << "| ";
            for (TreeNode23* child : node->children) {
                if (child) nextLevel.push_back(child);
            }
        }
        cout << endl;
        currentLevel = nextLevel;
    }
}

//traverse and collect keys
void collectKeys(TreeNode23* node, vector<int>& keys) {
    if (!node) return;

    if (node->isLeaf) {
        for (int key : node->keys) keys.push_back(key);
    } else {
        for (size_t i = 0; i < node->keys.size(); i++) {
            if (i < node->children.size()) collectKeys(node->children[i], keys);
            keys.push_back(node->keys[i]);
        }
        if (!node->children.empty()) collectKeys(node->children.back(), keys);
    }
}

//insert keys
TreeNode23* build23Tree(vector<int>& keys, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;

    TreeNode23* node = new TreeNode23(false);
    node->keys.push_back(keys[mid]);

    if (start < mid) {
        node->children.push_back(build23Tree(keys, start, mid - 1));
    } else {
        node->children.push_back(nullptr);
    }

    if (mid + 1 <= end) {
        node->children.push_back(build23Tree(keys, mid + 1, end));
    } else {
        node->children.push_back(nullptr);
    }

    return node;
}

TreeNode23* merge23Trees(TreeNode23* tree1, TreeNode23* tree2) {
    vector<int> keys;

    collectKeys(tree1, keys);
    collectKeys(tree2, keys);

    sort(keys.begin(), keys.end());

    // Rebuild new
    return build23Tree(keys, 0, keys.size() - 1);
}

int main() {
    TreeNode23* tree1 = new TreeNode23(false);
    tree1->keys = {10, 20};
    tree1->children = {
        new TreeNode23(true), new TreeNode23(true), new TreeNode23(true)
    };
    tree1->children[0]->keys = {5};
    tree1->children[1]->keys = {15};
    tree1->children[2]->keys = {25};

    TreeNode23* tree2 = new TreeNode23(false);
    tree2->keys = {35, 40};
    tree2->children = {
        new TreeNode23(true), new TreeNode23(true), new TreeNode23(true)
    };
    tree2->children[0]->keys = {30};
    tree2->children[1]->keys = {38};
    tree2->children[2]->keys = {50};

    TreeNode23* mergedTree = merge23Trees(tree1, tree2);

    cout << "Merged 2-3 Tree (Level-Order):" << endl;
    levelOrderTraversal(mergedTree);

    return 0;
}
