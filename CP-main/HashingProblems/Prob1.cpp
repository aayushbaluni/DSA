#include<bits/stdc++.h>
using namespace std;


void Solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	unordered_map<int, int> m;
	for(int i=0;i<n;i++){
		int z=k-arr[i];
		if(m.find(z)!=arr.end()){
			cout<<i<<" "<<m[z]<<endl;
			return;
		}
		map[arr[i]]=i;
	}
	cout<<"not found"<<endl;
	return;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}