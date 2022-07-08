#include<bits/stdc++.h>
using namespace std;
long long Place(int n,int m,vector<vector<long> >dp){
	if(n==0&& m==0) return 1;
	if(n<0 || m<0) return 0;
	if(dp[n][m]!=-1) return dp[n][m];
	int left = Place(n-1,m,dp);
	int right=Place(n,m-1,dp);
	dp[n][m]=left+right;
	return left+right;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<long> > dp(n,vector<long>(m,-1));
	cout<<Place(n-1,m-1,dp);
}
