#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#define N 202
#define M 202

using namespace std;

struct edge{
	int v, w;
};
typedef struct edge Edge;
int n, m;
vector<Edge> G[N];
int d[N];
bool in[N];
int ans = 0;

void showGraph(int cnt){
	cout << "Time: " << cnt << endl;
	for(int i = 1; i <= n; i++){
		for(vector<Edge>::iterator pt = G[i].begin(); pt != G[i].end(); pt++){
			Edge e = *pt;
			cout << i << " " << e.v << " " << e.w << endl;
		}
	}
}
bool bfs(){
	memset(d, -1, sizeof(d));
	memset(in, 0, sizeof(in));
	queue<int>q;
	d[1] = 0;
	in[1] = true;
	q.push(1);
	while(!q.empty()){
		int temp = q.front();
		for(vector<Edge>::iterator pt = G[temp].begin(); pt != G[temp].end(); pt++){
			Edge tt = *pt;
			int v = tt.v, w = tt.w;
			if(w && (d[v] == -1 || d[v] > d[temp] + 1)){
				d[v] = d[temp] +1;
				if(!in[v]){
					in[v] = true;
					q.push(v);
				}
			}
		}
		q.pop();
	}
	return d[n] == -1 ? false : true;

}

vector<Edge> G1[N];
vector<vector<Edge>::iterator> seq;
void dfs(int u){
	//cout << u << endl;
	if(u == n){
		//iterate the edge
		int flow = -1;
		for(vector<vector<Edge>::iterator>::iterator pt = seq.begin(); pt != seq.end(); pt++){
			Edge e = **pt;
			int v = e.v, w = e.w;
			//cout << v << "|" << w << endl;
			if(flow == -1)flow = w;
			flow = min(flow, w);
		}
		for(vector<vector<Edge>::iterator>::iterator pt = seq.begin(); pt != seq.end(); pt++){
			Edge e = **pt;
			int v = e.v, w = e.w - flow;
			//cout << v << "||" << w << endl;
			(*(*pt)).w -= flow;
			if(pt == seq.begin()){
				Edge temp{1, flow};
				G1[v].push_back(temp);
			}
			else{
				e = **(pt - 1);
				int bv = e.v;
				Edge temp{bv, flow};
				G1[v].push_back(temp);
			}
		}
		ans += flow;
		return;
	}
	for(vector<Edge>::iterator pt = G[u].begin(); pt != G[u].end(); pt++){
		Edge e = *pt;
		int v = e.v, w = e.w;
		if(w && d[v] == d[u] + 1){
			seq.push_back(pt);
			dfs(v);
			seq.pop_back();
		}
	}
}


int main(){
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Edge e{v, w};
		G[u].push_back(e);
	}
	int cnt = 0;
	while(bfs()){
		//for(int i = 1; i <= n; i++)cout << d[i] << " "; cout << endl;
		dfs(1);
		for(int i = 1; i <= n; i++){
			for(vector<Edge>::iterator pt = G1[i].begin(); pt != G1[i].end(); pt++)
				G[i].push_back( *pt );
			G1[i].clear();
		}
		//cout << endl;
		if(++cnt == 5) break;
		//showGraph(cnt);
	}
	cout << ans << endl;
}
