int fib(int N){
    if(N<1) return 0;
    //memo initialized as 0
    vector<int> memo(N+1, 0);
    //initialize the easiest condition
    return helper(memo, N);
}
int helper(vector<int>& memo, int n){
    //base case
    if(n == 1 || n==2) return 1;
    //having calculated
    if(memo[n] != 0 ) return memo[n];
    memo[n] = helper(memo, n-1) + helper(memo, n-2);
    return memo[n];
}