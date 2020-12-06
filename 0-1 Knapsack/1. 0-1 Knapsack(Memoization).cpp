/*
 * Parent Problem: 0-1 Knapsack
 * Problem Name: 0-1 Knapsack
 * Type: Memoization DP
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

ll dp[(int)1e5+500][100+50];

ll knapSack(ll W, ll wt[], ll val[], ll n){
	if(n == 0 || W == 0) return 0;
	if(dp[W][n] != -1) return dp[W][n];
	if(wt[n-1]<=W){
		return dp[W][n] = max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
	}else{
		return dp[W][n] = knapSack(W,wt,val,n-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("../input.txt","r",stdin);

	memset(dp,-1,sizeof dp);
	ll N,W;
	cin >> N >> W;
	ll wt[N],val[N];
	for (int i = 0; i < N; ++i) {
		cin >> wt[i] >> val[i];
	}
	cout << knapSack(W,wt,val,N) close
}
