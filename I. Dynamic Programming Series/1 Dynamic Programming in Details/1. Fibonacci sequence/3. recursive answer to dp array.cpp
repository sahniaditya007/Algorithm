int fib(int n){
    if(n==2 || n==1) return 1;
    int prev = 1; int curr =1;
    for(i=3;i<=n;i++){
        int sum = prev + curr;
        curr = prev;
        prev = curr;
    }
    return curr;
}