int dp[(int)1e4+1][(int)1e4+1];
int solve(vector<int> & arr, int sum, int n){
    if(sum == 0 && n == 0) return 1;
    if(n == 0) return 0;
    if(dp[sum][n] != -1) return dp[sum][n];
    if(arr[n-1] <= sum){
        return dp[sum][n] = solve(arr,sum-arr[n-1],n-1) + solve(arr,sum,n-1);
    }else{
        return dp[sum][n] = solve(arr,sum,n-1);
    }
}
