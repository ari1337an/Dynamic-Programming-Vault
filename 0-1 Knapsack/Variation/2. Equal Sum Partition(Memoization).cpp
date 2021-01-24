int dp[300+1][300+1];
bool solve(vector<int> & arr, int sum, int n){
    if(sum == 0) return true;
    if(n == 0) return false;
    if(dp[sum][n] != -1) {
        return ((dp[sum][n] == 1) ? 1 : 0);
    }
    if(arr[n-1] <= sum){
        if((solve(arr,sum-arr[n-1],n-1) || solve(arr,sum,n-1))) dp[sum][n] = 1;
        else dp[sum][n] = 0;
    }else{
        if(solve(arr,sum,n-1))dp[sum][n] = 1;
        else dp[sum][n] = 0;
    }
    return ((dp[sum][n] == 1) ? 1 : 0);
}

bool canPartition(vector<int>& nums) {
    memset(dp,-1,sizeof dp);
    int sum = accumulate(all(nums),0);
    if(sum%2 != 0) return false;
    return solve(nums,sum/2,nums.size());
}
