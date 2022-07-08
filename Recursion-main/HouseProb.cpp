#include<bits/stdc++.h>
using namespace std;

map<int,int> dp; 
int MaxAd(int index,int arr[]){
	if(index==0)return arr[0];
	if(index<0)return 0;
	if(dp.find(index)!=dp.end()) return dp[index];
	int left=arr[index]+MaxAd(index-2,arr);
	int right=0+MaxAd(index-1,arr);
	dp[index]=max(left,right);
	return max(left,right);
}

int main(){
	int s;
	cin>>s;
	int arr[s];
	for(int i=0;i<s;i++){
		cin>>arr[i];
	}
	cout<<MaxAd(s,arr);

}