void inorder(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
    if (!root) return;
    inorder(root->left, prev, first, second);
    if (prev && root->val < prev->val) {
        if (!first) first = prev;
        second = root;
    }
    prev = root;
    inorder(root->right, prev, first, second);
}

void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    inorder(root, prev, first, second);
    if (first && second) swap(first->val, second->val);
}
