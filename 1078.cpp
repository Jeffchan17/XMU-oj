#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define N 101

using namespace std;
int a[N][N], ans, n, d[N], in[N];
queue<int> q;

void Start(int u){
	memset(d, -1, sizeof(d));
	memset(in, 0, sizeof(in));
	d[u] = 0;
	q.push(u);
	in[u] = true;
	while(!q.empty()){
		int temp = q.front();
		for(int i = 1; i <= n; i++){
			if(a[temp][i] && ((d[i] > d[temp] + 1) || d[i] == -1)){
				d[i] = d[temp] + 1;
				if(!in[i]){
					q.push(i);
					in[i] = true;
				}
			}
		}
		q.pop();
		in[temp] = false;
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++){
		Start(i);
		int temp = -1;
		for(int j = 1; j <= n; j++)
			if(d[j] == -1){
				cout << -1 << endl;
				return 0;
			}
			else temp = max(temp, d[j]);
		if(ans == 0) ans = temp;
		else ans = max(ans, temp);
	}
	cout << --ans << endl;
}
