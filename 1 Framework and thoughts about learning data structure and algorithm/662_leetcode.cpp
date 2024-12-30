//i ssme width nikalni hai ek binary tree ki

// tuf
// width ->  no. of nodes in a level between any two nodes
// 0 based indexing mei (2*i+1)(2*i+2) se har node t
// 1 based indexing mei (2*i)(2*i+1)
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

/*
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution{
    public:
        int widthofBinaryTree(TreeNode* root){
            if (!root)
                return 0;
            
            queue<pair<TreeNode*, long long>> q;
            q.push({root, 0});
            int ans = 0;

            while(!q.empty()){
                int size = q.size();
                long long min = q.front().second;
                long long first, last;

                for(int i = 0; i< size; i++){
                    long long cur_id = q.front().second - min;
                    TreeNode* node = q.front().first;
                    q.pop;

                    if (i == 0) first = cur_id;
                    if (i == size - 1) last = cur_id;

                    if (node->left)
                        q.push({node->left, cur_id * 2 + 1});
                    if (node->right)
                        q.push({node->right, cur_id * 2 + 2});
                }

                ans = max(ans, static_cast<int>(last - first + 1));
            }

            return ans;
        }
}