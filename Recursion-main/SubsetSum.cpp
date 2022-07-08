#include<bits/stdc++.h>
using namespace std;

bool Solve(int i,int n,int arr[],int target,vector<vector<int> > &dp){
	if(i==n  || target<0) return false;
	if(dp[i][target]!=-1) return dp[i][target];
	if(target==0) return true;
	bool left= Solve(i+1,n,arr,target-arr[i],dp);
	bool right=Solve(i+1,n,arr,target,dp);
	return dp[i][target]=(left || right);
}

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<vector<int> > dp(n+1,vector<int>(k+1,-1));
	if(Solve(0,n,arr,k,dp)) cout<<"True"<<endl;
	else cout<<"false"<<endl;
}
