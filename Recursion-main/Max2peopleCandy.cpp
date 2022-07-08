#include<bits/stdc++.h>
using namespace std;
//it can also be used for an subset of equal sizes with equal sum.
long long Solve(int i,int j,int j2,int n,int m,vector<vector<int> > &v,vector<int> ele,vector<vector<vector<int> > > &dp ){
	if(i>n)return 0;
	if(i==n-1){
		if(j==j2) return v[i][j];
		else return v[i][j]+v[i][j2];
	}
	if(j<0 || j>=m ) return 0;
	if( j2<0 || j2 >=m) return 0;
	if(dp[i][j][j2]!=-1)return dp[i][j][j2];
	long long maxi=0;
	for(int k=0;k<ele.size();k++){
		for(int l=0;l<ele.size();l++){
			 long long val=0;
			 if(j==j2) val=v[i][j];
			 else val=v[i][j]+v[i][j2];
			 
			 val+=Solve(i+1,j+ele[k],j2+ele[l],n,m,v,ele,dp);
			 maxi=max(maxi,val);
		}
	}
	return  dp[i][j][j2]=maxi;
}


int main(){
	
	int n,m;
	cin>>n>>m;
	vector<vector<int> > v(n,vector<int> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}
	vector<vector<vector<int> > > dp(n,vector<vector<int> > (m,(vector<int> (m,-1))));
vector<int> ele;
ele.push_back(-1);
ele.push_back(0);
ele.push_back(1);
	cout<<Solve(0,0,m-1,n,m,v,ele,dp)<<endl;
}
