#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#define N 100001

using namespace std;

struct edge{
	int t, w;
};

typedef struct edge Edge;
vector<Edge> G[N];
int d[N];
bool in[N];
queue<int> q;

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Edge temp{v, w};
		G[u].push_back(temp);
		temp.t = u; temp.w = w;
		G[v].push_back(temp);
	}
	memset(d, -1, sizeof(d));
	d[1] = 0;
	q.push(1);
	in[1] = true;
	while(!q.empty()){
		int v = q.front();
		for(vector<Edge>::iterator pt = G[v].begin(); pt != G[v].end(); pt++){
			Edge e = *pt;
			int t = e.t;
			int w = e.w;
			if(d[t] == -1 || d[t] > d[v] + w){
				d[t] = d[v] + w;
				if(!in[t]){
					q.push(t);
					in[t] = true;
				}
			}
		}
		q.pop();
		in[v] = false;
	}
	cout << d[n] << endl;
}
