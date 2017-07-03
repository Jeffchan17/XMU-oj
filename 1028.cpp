#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAXN 1001
#define MAXV 8193

using namespace std;

struct item{
	int m, v;
};

int N;
typedef struct item Item;

vector<Item> Bag;
vector<int> ans;
int f[MAXN][MAXV];

int in(){
	int n, m;
	cin >> n >> m;
	N = n;
	for(int i = 0; i < n; i++){
		int mi;
		cin >> mi;
		Item a{mi, 0};
		Bag.push_back(a);
	}
	for(int i = 0; i < n; i++){
		int vi;
		cin >> vi;
		Bag[i].v = vi;
	}
	return m;
}

int main(){
	int V = in();
	for(int i = 0; i < N; i++){
		for(int j = V; j >= 0; j--){
			int temp = f[i+1][j];
			f[i+1][j] = f[i][j];
			if(j >= Bag[i].m)f[i+1][j] = max(f[i][j], f[i][j - Bag[i].m] + Bag[i].v);
			f[i+1][j] = max(f[i+1][j], temp);
		}
	}
	int cnt = 0;
	while(N){
		if(V >= Bag[N - 1].m && f[N][V] == f[N - 1][V - Bag[N - 1].m] + Bag[N - 1].v){
			cnt++;

			V -= Bag[N - 1].m;
			ans.push_back(N);
		}
		N--;
	}
	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for(vector<int>::iterator pt = ans.begin(); pt != ans.end(); pt++)
		printf(pt == ans.end() - 1 ? "%d\n" : "%d ", *pt);
}
