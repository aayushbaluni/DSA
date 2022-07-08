#include<bits/stdc++.h>
using namespace std;

bool Solve(int i,int n,int arr[],int target,int count,vector<vector<int> > &dp){
	if(i==n  || target<0) return false;
	if(dp[i][target]!=-1) return dp[i][target];
	if(target==0 && count==n/2) return true;
	bool left= Solve(i+1,n,arr,target-arr[i],count+1,dp);
	bool right=Solve(i+1,n,arr,target,count,dp);
	return dp[i][target]=(left || right);
}

int main(){
	int n;
	cin>>n;
	int sum=0;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(n%2!=0 || sum%2!=0){
		cout<<"False"<<endl;
		return 0;
	}
	vector<vector<int> > dp(n+1,vector<int>((sum/2)+1,-1));
	if(Solve(0,n,arr,sum/2,0,dp)) cout<<"True"<<endl;
	else cout<<"false"<<endl;
}
