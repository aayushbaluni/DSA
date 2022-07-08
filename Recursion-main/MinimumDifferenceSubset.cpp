#include<bits/stdc++.h>
using namespace std;

bool Solve(int i,int n,int arr[],vector<vector<int> > &st,int sum){
	if(i==n && sum==0) return true;
	if(i==n && sum!=0) return false;
	if(sum<0) return false;
	bool left=Solve(i+1,n,arr,st,sum-arr[i]);
	bool right=Solve(i+1,n,arr,st,sum);
	return (left || right);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
	cin>>arr[i];
	sum+=arr[i];	
	}
	vector<bool> dp(sum+1,false);
	vector<vector<int> > st (n,vector<int> (sum+1,-1)); 
	for(int i=0;i<sum+1;i++){
		dp[i]=Solve(0,n,arr,st,i);
	}
	int mini=INT_MAX;
	for(int i=0;i<sum+1;i++){
		if(dp[i]){
			int sum2=0;
			int diff=0;
			if(sum>i) {
			sum2=sum-i;	
			
			}
			else{
			sum2=i-sum;	
			} 
			diff=sum2 -i;
			diff=abs(diff);
			
			mini=min(mini,diff);
		}
	}
	cout<<mini<<endl;
}
