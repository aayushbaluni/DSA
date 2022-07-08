#include<bits/stdc++.h>
using namespace std;

bool CycleDFS(int curr,int prev,vector<int> &arr,vector<int>adj[]){
	arr[curr]=1;
	for(int i=0;i<adj[curr].size();i++){
			if(!arr[adj[curr][i]]){
				 if(CycleDFS(adj[curr][i],curr,arr,adj)) return true;
			}
			else if(prev!=adj[curr][i]) return true;
		}
	
	return false; 
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(CycleDFS(i,-1,vis,adj)){
				cout<<"True"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
}
