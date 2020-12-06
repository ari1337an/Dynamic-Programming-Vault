/*
 * Parent Problem: 0-1 Knapsack
 * Problem Name: 0-1 Knapsack
 * Type: Iterative DP
 * 
 * Problem Link: https://atcoder.jp/contests/dp/tasks/dp_d
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define PI acos(-1)
#define debug cerr <<
#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define close << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define get_random(x) uniform_int_distribution<int>(0, x-1)(rng)

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("../input.txt","r",stdin);

	// Inputs
	ll N,W;
	cin >> N >> W;
	vector<ll> wt(N),val(N);
	for (int i = 0; i < N; ++i) {
		cin >> wt[i] >> val[i];
	}

	// Dynamic Programming
	ll dp[N+1][W+1];
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < W + 1; ++j) {
			if(i == 0 || j == 0) dp[i][j] = 0LL;
		}
	}
	for (ll i = 1; i < N + 1; ++i) {
		for (ll j = 1; j < W + 1; ++j) {
			if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[N][W] close

}
