//https://leetcode.com/problems/recover-binary-search-tree
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
class Solution{
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    private:
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if (prev != NULL &&(root->val < prev->val)){
            //If this is the first violation, mark these two nodes as
            //'first' and 'middle'
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            //If this is second violation, mark this node as last
            else
            last = root;
        }
        //Mark this node as previous
        prev = root;
        inorder(root->right);
    }
    public:
    void recoverTree(TreeNode* root){
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};