// Problem link: https://practice.geeksforgeeks.org/problems/rod-cutting/0
#include <bits/stdc++.h>
using namespace std;

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

int main() {
	int testcase;
	cin >> testcase;
	for(int i = 0; i< testcase;i++){
	    dp.clear();
	    int n;
	    cin >> n;
	    vector<int> length(n);
	    vector<int> price(n);
	    for(int j = 0; j< n;j++) length[j] = j+1;
	    
	    for(int j = 0; j< n;j++) cin >> price[j]; 
	
	    cout << solve(length,price,n,n) << "\n";
	}
	
	return 0;
}
