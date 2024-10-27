#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) { //tree to a string
    if (!root) return "# ";
    return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
}

TreeNode* deserialize(istringstream& ss) { //string to reconstruct the tree
    string val;
    ss >> val;
    if (val == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserialize(ss);
    node->right = deserialize(ss);
    return node;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedTree = serialize(root);
    cout << "Serialized: " << serializedTree << endl;

    istringstream ss(serializedTree);
    TreeNode* newRoot = deserialize(ss);
    cout << "Deserialized Root: " << newRoot->val << endl;

    return 0;
}
