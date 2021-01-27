int dp[1001][1001];

int solve(string x, string y, int n, int m){
    if(n == 0 || m == 0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1] == y[m-1]) return dp[n][m] = (1+solve(x,y,n-1,m-1));
    else return dp[n][m] = max(solve(x,y,n,m-1), solve(x,y,n-1,m));
}

int lcs(string x, string y, int n, int m){
    memset(dp,-1,sizeof dp);
    return solve(string x, string y, int n, int m);
}
