#include<bits/stdc++.h>
using namespace std;

int MaxSum(int i,int j,int n,int m,vector<vector<int> > arr,vector<vector<int> > &dp){
	if(i==n-1)return arr[i][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int down=arr[i][j]+MaxSum(i+1,j,n,m,arr,dp);
	int left=INT_MIN;
	int right=INT_MIN;
	if(j<m-1) right=arr[i][j]+MaxSum(i+1,j+1,n,m,arr,dp);
	if(j>0) left=arr[i][j]+MaxSum(i+1,j-1,n,m,arr,dp);
	int maxi=max(down,left);
	maxi=max(maxi,right);
	return maxi;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >  arr(n,vector<int>(m));
	vector<vector<int> >  dp(n,vector<int>(m,-1));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int best=INT_MIN;
	for (int i=0;i<m;i++){
		int curr=MaxSum(0,i,n,m,arr,dp);
		best=max(best,curr);
	}
	cout<<best<<endl;
}
