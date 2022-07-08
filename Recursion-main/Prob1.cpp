#include<bits/stdc++.h>
using namespace std;
//to find all posible sequence
void func(int index,int arr[],vector<int> v,int n,vector<vector< int> > &z){
	if(index==n) {
	z.push_back(v);
	return;
	} 
	v.push_back(arr[index]);
	func(index+1,arr,v,n,z);
	
	v.pop_back();
	func(index+1,arr,v,n,z);
	
}

//to find all possible sequece sum=k
void fun(int index,int arr[],vector<int> v,int n,vector<vector< int> > &z,int k,int sum){
	
	if(index==n){
		if(sum==k){
			z.push_back(v);
		}
		return;
	}
	v.push_back(arr[index]);
	sum+=arr[index];
	fun(index+1,arr,v,n,z,k,sum);
	v.pop_back();
	sum-=arr[index];
	fun(index+1,arr,v,n,z,k,sum);
}
// print all possible cases for sum=k
int funct(int i,int n,int arr[],int sum,int k){
	if(i==n) {
		if(sum==k)return 1;
		return 0;
	}
	sum+=arr[i];
	int left=funct(i+1,n,arr,sum,k);
	sum-=arr[i];
	int right=funct(i+1,n,arr,sum,k);
	return left+right;
}

int main(){
	int arr[3]={3,1,2};
	vector<int>v;
	vector<vector<int> >z;
	func(0,arr,v,3,z);
//	fun(0,arr,v,3,z,3,0);
//	funct(0,3,arr,0,3);
	sort(z.begin(),z.end());
	for(int i=0;i<z.size();i++){
		for(int j=0;j<z[i].size();j++){
			cout<<z[i][j]<<" ";
			
		}
		cout<<endl;
	}
}
