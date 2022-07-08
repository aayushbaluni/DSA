#include<bits/stdc++.h>
using namespace std;
map<int,int> m;

int countSteps(int index){
	if(index==1 || index==0) return 1;
	if(m.find(index)!=m.end()) return m[index];
	int left=countSteps(index-1);
	int right=countSteps(index-2);
	m[index]=left+right;
	return left+right;
}

int main(){
	cout<<countSteps(10);
}
