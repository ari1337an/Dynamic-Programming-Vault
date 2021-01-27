int dp[1001][1001];

string SCS_print(string x, string y, int n, int m){
    // Populate the LCS dp array
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
    
    // Partly same as LCS printing
    string scs;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            scs = x[i-1] + scs;
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]) {
                scs = x[i-1] + scs; // extra
                i--;
            }else{
                scs = y[j-1] + scs; // extra
                j--;
            }
        }
    }

    // because if x = "ae" and y = "" then lcs = "" but scs = "ae" hence we need to add them also.
    // 
    while(i > 0){
        scs = x[i-1] + scs;
        i--;
    }
    while(j > 0){
        scs = y[j-1] + scs;
        j--;
    }
    return scs;
}
