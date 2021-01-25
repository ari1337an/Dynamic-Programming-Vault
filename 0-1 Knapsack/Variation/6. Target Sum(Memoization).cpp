    unordered_map<int,unordered_map<int,int>> dp;
    int solve(vector<int> & arr, long long int sum, int n){
        if(sum == 0 && n == 0) return 1;
        if(n == 0) return 0;
        if(dp[sum][n]) return dp[sum][n];
        if(arr[n-1] <= sum){
            return dp[sum][n] = solve(arr,sum-arr[n-1],n-1) + solve(arr,sum,n-1);
        }else{
            return dp[sum][n] = solve(arr,sum,n-1);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        dp.clear();
        long long int sum = accumulate(nums.begin(),nums.end(),0);
        sum = sum + S;
        if(sum%2 != 0){
            return 0;
        }
        sum = sum / 2LL;
        return solve(nums, sum, nums.size());
    }
