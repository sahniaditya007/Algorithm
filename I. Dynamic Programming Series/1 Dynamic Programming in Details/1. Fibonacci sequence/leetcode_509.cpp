//https://leetcode.com/problems/fibonacci-number/description/
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0; // Base case: fib(0) = 0
        if (n == 1 || n == 2) return 1; // Base case: fib(1) = fib(2) = 1
        
        int prev = 1;
        int curr = 1;
        for (int i = 3; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};
