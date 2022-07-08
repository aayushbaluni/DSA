#include<bits/stdc++.h>
using namespace std;

//for minimum energy required to cross.

int func(int index,int arr[]){
	if(index==0) return  0;
	int l=func(index-1,arr)+abs(arr[index]-arr[index-1]);
	int r=INT_MAX;
	if(index>1){
	r=func(index-2,arr)+ abs(arr[index]-arr[index-2]);
	}
	
	return min(l,r);
}


int main(){

	int arr[6]={30,10,60,10,60,50};
	cout<<func(6,arr);
}