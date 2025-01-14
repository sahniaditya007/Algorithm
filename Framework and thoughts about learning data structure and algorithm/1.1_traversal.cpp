/* The so-called framework is a trick.
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

//Dynamic programming said that the problem of collecting changes, the brute-force solution is to traverse an n-treew
/*def coinChange(coins: List[int], amount: int):

    def dp(n):
        if n == 0: return 0
        if n < 0: return -1

        res = float('INF')
        for coin in coins:
            subproblem = dp(n - coin)
            # no solution for sub questions 
            if subproblem == -1: continue
            res = min(res, 1 + subproblem)
        return res if res != float('INF') else -1
    
    return dp(amount)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Memoization map to store results of subproblems
        unordered_map<int, int> memo;
        
        // Helper function for recursion
        function<int(int)> dp = [&](int n) -> int {
            // Base cases
            if (n == 0) return 0;       // No coins needed for amount 0
            if (n < 0) return -1;       // Invalid case

            // If result for this amount is already computed, return it
            if (memo.find(n) != memo.end()) return memo[n];

            int res = INT_MAX;          // Initialize result as infinity
            for (int coin : coins) {
                int subproblem = dp(n - coin); // Solve subproblem
                if (subproblem == -1) continue; // Skip if no solution
                res = min(res, 1 + subproblem); // Update result
            }

            // Store result in memoization map
            memo[n] = (res == INT_MAX) ? -1 : res;
            return memo[n];
        };

        // Call helper function for the initial amount
        return dp(amount);
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = solution.coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}


/*
To sum up, for those who are afraid of algorithms, you can do the exercises of the relevant topics of trees first.
 Try to see the problems in relation to the framework, rather than by focusing on details.
From the perspective of framework we can extract and expand based on the framework.
This can not only allow us to quickly understand the core logic of other people's solutions, but also help us find the correct direction of thinking when working on our own solutions.
Of course, if the details are wrong, you can't get the right answer.
But as long as there is a framework, you can't be too wrong, because your direction is right.
This kind of thinking is very important.
Sometimes I write the solution according to the process of finding the state transition equation summarized in the dynamic planning explanation.
To be honest, I don't know why it's right. Anyway, it's right...
This is the power of a framework. It can ensure that you can still write the right program even when you are sleepy; even if you can't do anything, you can be at a higher level than others.
*/