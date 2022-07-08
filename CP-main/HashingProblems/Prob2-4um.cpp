#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	vector<vector<int> > ans;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int target=k-(arr[i] + arr[j]);
			int l=j+1;
			int r=n-1;
			while(l<r){
				int t=arr[l]+arr[r];
				if(t<target) l++;
				else if(t>target) r--;
				else{
					vector<int> quadruplet(4,0);
					quadruplet[0]=arr[i];
					quadruplet[1]=arr[j];
					quadruplet[2]=arr[l];
					quadruplet[3]=arr[r];
				ans.push_back(quadruplet);
				
				while(l<r && arr[l]==quadruplet[2]) ++l;
				while(l<r && arr[r]==quadruplet[3]) --r;	
				}
			}
				while(j+1<n && arr[j+1]==arr[j]) ++j;
		}
			while(i+1<n && arr[i+1]==arr[i]) ++i; 
	}
	for(int i=0;i=ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}