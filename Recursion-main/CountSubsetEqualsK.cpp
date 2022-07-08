#include<bits/stdc++.h>
using namespace std;


int Solve(int i,int n,int k,int arr[],int sum,vector<vector<int> > &dp,int count){
	if(i==n&& k==sum) return 1;
	if(i==n && sum!=k) return 0;
	if(dp[i][sum]!=-1)return dp[i][sum];
	if(sum>k) return 0;
	int left=Solve(i+1,n,k,arr,sum+arr[i],dp,count);
	int right=Solve(i+1,n,k,arr,sum,dp,count);
	return dp[i][sum]=left+right;
}

int main(){
	int n,k;
	cin>>n>>k;
	int sum=0;
	int arr[n];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	sum+=arr[i];
	}
	vector<vector<int> > dp(n+1,vector<int> (sum+1,-1));
	cout<<Solve(0,n,k,arr,0,dp,0);
}
