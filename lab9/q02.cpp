#include <iostream>
using namespace std;

struct AVLNode {
    int val;
    AVLNode *left, *right;
    int height;
    AVLNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y, int &rotationCount) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    rotationCount++;
    return x;
}

AVLNode* rotateLeft(AVLNode* x, int &rotationCount) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    rotationCount++;
    return y;
}

AVLNode* insert(AVLNode* node, int val, int &rotationCount) {
    if (!node) return new AVLNode(val);

    if (val < node->val) node->left = insert(node->left, val, rotationCount);
    else if (val > node->val) node->right = insert(node->right, val, rotationCount);
    else return node; // Duplicate keys are not allowed in AVL tree.

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalanceFactor(node);

    if (balance > 1 && val < node->left->val)
        return rotateRight(node, rotationCount);
    if (balance < -1 && val > node->right->val)
        return rotateLeft(node, rotationCount);
    if (balance > 1 && val > node->left->val) {
        node->left = rotateLeft(node->left, rotationCount);
        return rotateRight(node, rotationCount);
    }
    if (balance < -1 && val < node->right->val) {
        node->right = rotateRight(node->right, rotationCount);
        return rotateLeft(node, rotationCount);
    }

    return node;
}

int countRotations(int arr[], int n) {
    AVLNode* root = nullptr;
    int rotationCount = 0;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i], rotationCount);
    }
    return rotationCount;
}

int main() {
    int arr[] = {10, 20, 30, 25, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Total rotations: " << countRotations(arr, n) << endl;
    return 0;
}
