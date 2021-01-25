unordered_map<int, unordered_map<int,int>> dp;
int solve(vector<int> &length, vector<int> &price, int n, int len){
    if(len == 0 || n == 0) return 0;
    if(dp[n][len]) return dp[n][len];
    if(length[n-1] <= len){
        return dp[n][len] = max(price[n-1] + solve(length,price, n, len-length[n-1]), solve(length,price, n-1, len));
    }else{
        return dp[n][len] = solve(length,price, n-1, len);
    }
}
