int dp[1001][1001];
int LCS(string x, string y, int n, int m){
    int result = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(result, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return result;
}

int SCS(string a, string b, int n, int m){
    return n + m - LCS(a,b,n,m);
}
