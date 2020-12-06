/*
 * Parent Problem: 0-1 Knapsack
 * Problem Name: Subset Sum 
 * Type: Memoization DP
 * 
 * Problem Link: 
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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("../input.txt","r",stdin);

	memset(dp,-1,sizeof dp);
	int arr[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;

	cout << ((isSubsetSum(arr,sum,6))?"YES":"NO") close

}
