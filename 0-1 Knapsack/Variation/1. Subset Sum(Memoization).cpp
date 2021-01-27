int dp[30+1][6+1];

bool isSubsetSum(int arr[], int sum, int n){
	if(sum == 0) return true;
	if(n == 0) return false;
	if(dp[sum][n] != -1) {
		return ((dp[sum][n] == 1) ? 1 : 0);
	}

	if(arr[n-1] <= sum){
		if((isSubsetSum(arr,sum-arr[n-1],n-1) || isSubsetSum(arr,sum,n-1)))
			dp[sum][n] = 1;
		else
			dp[sum][n] = 0;
	}else{
		if(isSubsetSum(arr,sum,n-1))
			dp[sum][n] = 1;
		else
			dp[sum][n] = 0;
	}
	return ((dp[sum][n] == 1) ? 1 : 0);
}
