// Problem link: https://practice.geeksforgeeks.org/problems/coin-change2448/1
unordered_map<long long int,unordered_map<long long int,long long int>> dp;
long long int solve(int arr[], long long int sum, long long int n){
    if(sum == 0 && n == 0) return 1;
    if(n == 0) return 0;
    if(dp[sum][n]) return dp[sum][n];
    if(arr[n-1] <= sum){
        return dp[sum][n] = solve(arr,sum-arr[n-1],n) + solve(arr,sum,n-1);
    }else{
        return dp[sum][n] = solve(arr,sum,n-1);
    }
}
long long int count( int S[], int m, int n )
{
    dp.clear();
    return solve(S,(long long int)n,(long long int)m);
}
