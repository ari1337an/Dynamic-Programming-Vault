int dp[1001][1001];

string LCS_print(string x, string y, int n, int m){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcs = x[i-1] + lcs;
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    return lcs;
}
