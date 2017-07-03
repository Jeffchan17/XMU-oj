#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#define N 100010

using namespace std;

struct edge{
	int u, v, w;
	bool operator<(const struct edge & b) const{
		return w < b.w;
	}
};
typedef struct edge Edge;
int n, m, cnt, ans, fa[N];
vector<Edge> seq;

int findfa(int u){
	return fa[u] == u ? u : fa[u] = findfa(fa[u]);
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)fa[i] = i;
	for(int i = 1; i <= m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		Edge t{u, v, w};
		seq.push_back(t);
	}
	sort(seq.begin(), seq.end());
	for(vector<Edge>::iterator pt = seq.begin(); pt != seq.end(); pt++){
		Edge t = *pt;
		int u = t.u, v = t.v, w = t.w;
		fa[u] = findfa(u);
		fa[v] = findfa(v);
		if(fa[findfa(u)] != fa[findfa(v)]){
			fa[findfa(u)] = fa[findfa(v)];
			cnt++;
			ans+=w;
		}
	}
	printf("%d\n", cnt == n-1 ? ans : -1);
}
