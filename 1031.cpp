#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define N 201

using namespace std;

int a[N][N], b[N][N], c[N], f[N];
int ans;

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			b[i][j] = a[i][j] + b[i-1][j];
		}
	ans = a[1][1];
	for(int i = 1; i <= n; i++){
		for(int j = i; j <=n; j++){
			for(int k = 1; k <= n; k++)
				c[k] = b[j][k] - b[i-1][k];
			memset(f, -1, sizeof(f));
			for(int k = 1; k <= n; k++){
				f[k] = (f[k-1] >= 0 ? f[k-1] + c[k] : c[k]);
				ans = max(f[k], ans);
			}
		}
	}
	cout << ans << endl;
}
