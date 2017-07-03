#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#define N 101

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
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int temp;
			cin >> temp;
			Edge e = {j, temp};
			G[i].push_back(e);
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
