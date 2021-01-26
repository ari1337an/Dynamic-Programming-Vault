	unordered_map<int,unordered_map<int,int>> dp;
	int solve(int coins[], int size, int sum){
	    if(size == 0) return INT_MAX -1;
	    if(sum == 0) return 0;
	    if(dp[size][sum]) return dp[size][sum];
	    if(coins[size-1] <= sum){
	        return dp[size][sum] = min(1+solve(coins,size,sum-coins[size-1]),solve(coins,size-1,sum));
	    }else{
	        return dp[size][sum] = solve(coins,size-1,sum);
	    }
	}
