#include<bits/stdc++.h>
using namespace std;


//Depth First Search
void dfs(int i,vector<int> &arr,vector<int> adj[],vector<int> &ans){
	ans.push_back(i);
	stack<int> s;
	arr[i]=1;
	s.push(i);
	while(!s.empty()){
		s.pop();
		for(int j=0;j<adj[i].size();j++){
			if(!arr[adj[i][j]]){
				dfs(adj[i][j],arr,adj,ans);
			}
		}
	}
}


//Breadth First Search.
void bfs(int i,vector<int> &arr,vector<int> adj[],vector<int>  &ans){
	ans.push_back(i);
	arr[i]=1;
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		q.pop();
		for(int j=0;j<adj[i].size();j++){
			if(!arr[adj[i][j]]){
				bfs(adj[i][j],arr,adj,ans);
			}
		}
	}
}

//Cyclic Detection in BFS
bool CyclicBFS(int curr,vector<int>&arr,vector<int> adj[]){
	arr[curr]=1;
	queue<pair<int,int> > q;
	q.push({curr,-1});
	while(!q.empty()){
		int curr=q.front().first;
		int prev=q.front().second;
		q.pop();
		for(int i=0;i<adj[curr].size();i++){
			if(!arr[adj[curr][i]]){
				arr[adj[curr][i]]=1;
				q.push({adj[curr][i],curr});
			}
			else if(prev!=adj[curr][i]) return true;
		}
	}
	
	
	return false;
}




int main(){
//Insert
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//traversal array
	vector<int> arr(n+1,0);
	vector<int> ans;

//		traversal
int i=0;
	for( i=1;i<=n;i++){
		if(!arr[i]){
//			bfs(i,arr,adj,ans);
			dfs(i,arr,adj,ans);
//			if(CyclicBFS(i,arr,adj)){
//				cout<<"Yes"<<endl;
//			}
		}
	}

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
}
