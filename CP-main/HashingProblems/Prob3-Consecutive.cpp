#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	 cin>>n;
	 int arr[n];
		set<int> m;
	 for(int i=0;i<n;i++){
	 	cin>>arr[i];
			m.insert(arr[i]);
	 }
	 int best=0;
	 sort(arr,arr+n);
		for(int i=0;i<n;i++){
			
				if(!m.count(arr[i]-1)){
					int current=arr[i];
					int count=1;
					while(m.count(current+1)){
						count++;
						current++;
					}
					best=max(count,best);
				}
		}
		
		cout<<best<<endl;
}