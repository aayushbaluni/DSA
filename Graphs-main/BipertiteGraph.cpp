#include<bits/stdc++.h>
using namespace std;
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
	//COLOR ONLY 0,1
	vector<int> col(n+1,-1);
	
	for(int i=1;i<=n;i++){
	if(col[i]==-1){
		queue<int> q;
		q.push(i);
		col[i]=1;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int i=0;i<adj[t].size();i++){
				if(col[adj[t][i]]==-1){
					col[adj[t][i]]=1-col[t];
					q.push(adj[t][i]);
				}else if(col[t]==col[adj[t][i]]){
					cout<<"flase"<<endl;
					return 0;
				}
			}
		}
	}
	}
	cout<<"Yes"<<endl;
}
