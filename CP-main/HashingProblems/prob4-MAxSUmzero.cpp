#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	 cin>>n;
	 int arr[n];
	
	 for(int i=0;i<n;i++){
	 	cin>>arr[i];
	 }
	 unordered_map<int , int> m;
	 int sum=arr[0];
	 int count=0;
	 for(int i=1;i<n;i++){
	 	sum+=arr[i];
	 	if(m.find(sum)!=m.end()){
	 		int curr=i-m[sum];
	 		count=max(curr,count);
		 }
		 else{
		 	m[arr[i]]=i;
		 }
	 }
	 cout<<count<<endl;
}