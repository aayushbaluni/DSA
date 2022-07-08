#include<bits/stdc++.h>
using namespace std;

	vector<vector<string> > ans;
bool isPalindrom(string s,int b,int e){
	if(b==e) return true;
	while(b<e){
		if(s[b]!=s[e])return false;
		b++;
		e--;
	}
	return true;
}

void Check(string s,int start,vector<string>curr){
	if(start==s.length()){
		
		return;
	}
	for(int i=start;i<s.length();i++){
		if(isPalindrom(s,start,i)){
			curr.push_back(s.substr(start,i-start+1));
			ans.push_back(curr);
			curr.pop_back();
		}
	}
	Check(s,start+1,curr);

} 

int main(){
	string s;
	cin>>s;
	vector<string> curr;
	Check(s,0,curr);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
