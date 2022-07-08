#include<bits/stdc++.h>
using namespace std;
long long MinSum(int i,int j,int n,vector<vector<int> > v,vector<vector<int> > dp){
	if(i==n-1) return v[i][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int down=v[i][j]+MinSum(i+1,j,n,v,dp);
	int diag=v[i][j]+MinSum(i+1,j+1,n,v,dp);
	dp[i][j]=min(down,diag);
	return min(down,diag);
}



int main(){
	vector<vector<int> > v;
	int n;
	cin>>n;
	vector<vector<int> > dp(n,vector<int>(n,-1));
	for(int i=0;i<n;i++){
		vector<int> c;
		for(int j=0;j<i+1;j++){
			int a;
			cin>>a;
			c.push_back(a);
		}
		v.push_back(c);
	}
	cout<<MinSum(0,0,n,v,dp);
}
