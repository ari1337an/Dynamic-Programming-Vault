int dp[1001][1001];
int LCS(string x, string y, int n, int m){
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
  return dp[n][m];
}
pair<int, int> solve(string A, string B, int n, int m){
    int lcs = LCS(A,B,n,m);
    pair<int, int> deletion_insertion = {n-lcs, m-lcs};
    return deletion_insertion;
}
