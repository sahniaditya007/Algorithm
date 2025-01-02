//issme bst diya hoga lekin wo thoda sa galt hoga haame usse thik karna hai swap karke 

//fkn
void traverse(TreeNode* node) {
    if (!node) return;
    traverse(node->left);
    if (node->val < prev->val) {
        s = (s == NULL) ? prev : s;
        t = node;
    }
    prev = node;
    traverse(node->right);
}

//tuf
