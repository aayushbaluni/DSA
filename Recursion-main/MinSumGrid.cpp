#include<bits/stdc++.h>
using namespace std;

long long CountMin(int i,int j,vector<vector<long> > arr,vector<vector<long> > dp){
	if(i==0 && j==0)return arr[i][j];
	//all elements under 1e7;
	if(i<0 || j<0) return 1e7;
	if(dp[i][j]!=-1)return dp[i][j];
	int left=arr[i][j]+CountMin(i-1,j,arr,dp);
	int right=arr[i][j]+CountMin(i,j-1,arr,dp);
	dp[i][j]=min(left,right);
	return min(left,right);	
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<long> > arr(n,vector<long>(m));
	vector<vector<long> > dp(n,vector<long>(m,-1));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	cout<<CountMin(n-1,m-1,arr,dp);
}
