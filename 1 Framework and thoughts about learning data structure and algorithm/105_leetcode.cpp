/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and
inorder is the inorder traversal of the same tree, construct and return the binary tree.*/
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

// neet
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int mid = distance(inorder.begin(), it);
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPreorder(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

//fkn
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i; // Map value to its index in inorder
        }
        return helper(preorder, 0, preorder.size() - 1, 
                      inorder, 0, inorder.size() - 1, 
                      inMap);
    }

private:
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, 
                     vector<int>& inorder, int inStart, int inEnd, 
                     unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]); // Root is the first node in preorder
        int inRoot = inMap[root->val]; // Index of root in inorder
        int numsLeft = inRoot - inStart; // Nodes in the left subtree

        root->left = helper(preorder, preStart + 1, preStart + numsLeft, 
                            inorder, inStart, inRoot - 1, inMap);
        root->right = helper(preorder, preStart + numsLeft + 1, preEnd, 
                             inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};