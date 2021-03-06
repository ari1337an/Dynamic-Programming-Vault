int dp[(int)1e4+2][(int)1e4+2];
//unordered_map<int,unordered_map<int,bool>> dp; // if segmentation fault, because of out of bound index
void bottom_up_subset_sum(int arr[], int n, int range_sum){
    for (int i = 0; i <= n ; ++i) {
        for (int j = 0; j <= range_sum + 1; ++j) {
            if(i == 0) dp[i][j] = false;
            if(j == 0) dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= range_sum + 1; ++j) {
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
