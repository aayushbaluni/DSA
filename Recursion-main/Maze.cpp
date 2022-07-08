#include<bits/stdc++.h>
using namespace std;

int CountWays(int i,int j,vector<vector<long> >arr,vector<vector<long> >dp){
	if(arr[i][j]==-1) return 0;
	if(i==0 &&j==0) return 1;
	if(i<0 || j<0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int left=CountWays(i-1,j,arr,dp);
	int right=CountWays(i,j-1,arr,dp);
	dp[i][j]=left+right;
	return left+right;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<long> >arr(n,vector<long>(m));
	vector<vector<long> > dp(n,vector<long>(m,-1));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	cout<<CountWays(n-1,m-1,arr,dp);
}
