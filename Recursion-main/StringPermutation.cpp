#include<bits/stdc++.h>
using  namespace std;
vector<vector<string> > v;

bool isPerrmutation(string s,int t,string small){
	
	string s1=s.substr(t,small.size());
	sort(s1.begin(),s1.end());
	
	if(s1.compare(small)==0){
	return true;
	}
	return false;
}

void Call(string s,int diff,int n,vector<string> v1,string small){
	for(int i=0;i<n-small.size()+1;i++){
		
	if(isPerrmutation(s,i,small)){
		v1.push_back(s.substr(i,small.size()));
		v.push_back(v1);
	}
	}
	
}


int main(){
		vector<string> v1;
	string s,small;
	cin>>s>>small;
	int diff=small.length()-1;
	sort(small.begin(),small.end());
	Call(s,diff,s.size(),v1,small);
	cout<<v.size()<<endl;
	
}
