#include<bits/stdc++.h>
using namespace std;

int Best(int index,vector<vector<int> > arr,int last,int t){
		int maxi=0;
	if(index==0){
		for(int i=0;i<t;i++){
			if(i!=last){
				maxi= max(maxi,arr[0][i]);
			}
		}
		return maxi;
	}
	for(int i=0;i<t;i++){
		if(i!=last){
			int value=arr[index][i]+if(i>0)Best(index-1,arr,i);
		maxi=max(maxi,value);
		}
	}
	return maxi;
}

int main(){
	int s,t;
	cin>>s>>t;
	vector<vector<int> > arr(s,vector<int>(t,0));
	for(int i=0;i<s;i++){
		for(int j=0;j<t;j++){
			cin>>arr[i][j];
		}
	}
	cout<<Best(s-1,arr,3,t);

	

}
