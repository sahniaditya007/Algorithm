/*The so-called framework is a trick.
No matter add, delete, insert or modify, these codes are never separated from the structure.
You can take this structure as the outline and add code on the framework according to specific problems.
The following will give specific examples.*/

// Array traversal framework, typical linear iterative structure:
void traverse(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
        // iteratively visit arr[i]
    }
}

//Linked list traversal framework has both iterative and recursive structure：
/* Basic node of the single linked list */
class ListNode {
    int val;
    ListNode next;
}

void traverse(ListNode head) {
    for (ListNode p = head; p != null; p = p.next) {
        // iteratively p.val
    }
}

void traverse(ListNode head) {
    // recursively head.val
    traverse(head.next)
}

//Binary tree traversal framework, typical nonlinear recursive traversal structure：
/* Basic node of the binary tree */
class TreeNode {
    int val;
    TreeNode left, right;
}

void traverse(TreeNode root) {
    traverse(root.left)
    traverse(root.right)
}

//The binary tree framework can be extended to the n-tree traversal framework:
/* Basic node of the N-tree */
class TreeNode {
    int val;
    TreeNode[] children;
}

void traverse(TreeNode root) {
    for (TreeNode child : root.children)
        traverse(child)
}