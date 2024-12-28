//issme path nikalna hai tree ka

//fkn
int ans = INT_MIN;
int oneSideMax(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = max(0, oneSideMax(root->left));
    int right = max(0, oneSideMax(root->right));
    ans = max(ans, left + right + root->val);
    return max(left, right) + root->val;
}

//tuf
//val + (maxL + maxR) {max sum on the left and max sum in the right}
