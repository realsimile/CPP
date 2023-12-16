//Finds out if the given array is ascending or descending, made with two dimensional dynamic programming
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin>>n;
	int a[n]; int dp[n][2];
	
	for (int k = 0; k < n; k++){
		cin>>a[k];
		dp[k][0] = 1;
		dp[k][1] = 1;
	} 
	
	for (int k = 1; k < n; k++){
		if (a[k] >= a[k - 1]) dp[k][0] = dp[k - 1][0] + 1;
		else dp[k][0] = 1;
		
		if (a[k] <= a[k - 1]) dp[k][1] = dp[k - 1][1] + 1;
		else dp[k][1] = 1;
	}
	
	int mx = 0;
	
	for (int k = 0; k < n; k++) mx = max({dp[k][0], dp[k][1], mx});
	
	if (mx == n) cout<<"Array is ascending/descending";
	else cout<<"Array is not ascending/descending";
	
	return 0;
}
