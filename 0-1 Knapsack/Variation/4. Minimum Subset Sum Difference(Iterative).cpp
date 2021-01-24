/*
 * We need to divide the array into two subssets, with each sum being s1 and s2;
 * Let s1 be the smallest(or equal)
 * 
 * We need to minimize, s2-s1
 * which is actually, (RANGESUM - s1)-s1
 * which is actually, RANGESUM - 2*s1
 *
 * We can find the s1 in the last row of the n*sum dp array(of the subset sum) (s1 is in the first half of the row)
 * We can reduce it even more by getting the maximum of that first half.
 * We can even more reduce the problem if we only get the subset sum of ceil(RANGESUM/2.0) because we only need half of the array.
 */

unordered_map<int,unordered_map<int,bool>> dp;
void bottom_up_subset_sum(int arr[], int n, int range_sum){
    for (int i = 0; i <= n ; ++i) {
        for (int j = 0; j <= (int)ceil(range_sum/2.0)+1; ++j) {
            if(i == 0) dp[i][j] = false;
            if(j == 0) dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= (int)ceil(range_sum/2.0)+1; ++j) {
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
int minDiffernce(int n, int range_sum){
    int s1 = 0;
    for (int j = 0; j <= range_sum/2; ++j) {
        if(dp[n][j]) s1 = max(s1, j);
    }
    return range_sum-2*s1;
}
