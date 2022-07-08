#include<bits/stdc++.h>	
using namespace std;

int findMax(int index,int arr[],int last){
	if(index==last)return arr[last];
	if(index<last)return 0;
	int left=arr[index]+findMax(index-2,arr,last);
	int right=0+findMax(index-1,arr,last);
	return max(left,right);
}

int main()
{
	int t;
	cin>>t;
	int arr[t];
	for(int i=0;i<t;i++){
		cin>>arr[i];
	}
	int left =findMax(t-1,arr,1);
	int right=findMax(t-2,arr,0);
	cout<<max(left,right)<<endl;
	return 0;
}